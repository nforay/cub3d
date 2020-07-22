/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:00:18 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 02:01:31 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	post_display_update(t_params *params)
{
	params->framecount++;
	if (params->health <= 0)
		return ;
	if (params->shadecol.r > params->baseshadecol.r)
		params->shadecol.r -= 0.05;
	if (params->shadecol.g > params->baseshadecol.g)
		params->shadecol.g -= 0.05;
	if (params->shadecol.b > params->baseshadecol.b)
		params->shadecol.b -= 0.05;
	if (params->weaponcd > 0)
		params->weaponcd--;
	else if (params->firing && !params->weaponcd && params->ammo > 0)
	{
		params->weaponcd = params->weaponbasecd;
		params->ammo--;
	}
}

static void	draw_bonus_to_window(t_params *params)
{
	if (params->equiped & INV_GUN && params->w >= 40 && params->h >= 40)
		mlx_put_image_to_window(params->vars.mlx, params->vars.win,
			params->crosshair.img,
			(int)(params->w / 2 - params->crosshair.width / 2),
			(int)(params->h / 2 - params->crosshair.height / 2));
	if (params->equiped & INV_GUN && params->w >= 750 && params->h >= 300)
	{
		if (params->weaponcd > (int)(params->weaponbasecd * 0.5))
			mlx_put_image_to_window(params->vars.mlx, params->vars.win,
				params->weapf.img,
				(int)(params->w - params->weap.width),
				(int)(params->h - params->weap.height));
		else
			mlx_put_image_to_window(params->vars.mlx, params->vars.win,
				params->weap.img, (int)(params->w - params->weap.width),
				(int)(params->h - params->weap.height));
	}
	if (params->w >= 150 && params->h >= 50)
		mlx_put_image_to_window(params->vars.mlx, params->vars.win,
			params->hud.img, 40, (params->h - 40));
	post_display_update(params);
}

static int	interlaced_renderer(t_params *params)
{
	if (params->interlace)
		params->alternate = !params->alternate;
	return (params->alternate);
}

int			render_single_frame(t_params *p)
{
	t_frame	f;
	int		x;

	x = 0;
	newframe_init_sprite(p);
	while (x < p->w)
	{
		prepare_new_ray(p, &f, x);
		perform_digital_differential_analysis(p, &f);
		get_wall_data(p, &f, x);
		draw_stripe(p, &f, x);
		x++;
	}
	if (save_screenshot(p))
		perror("Error\nsave_screenshot");
	return (1);
}

int			render_frame(t_params *p)
{
	t_frame	f;
	int		x;

	x = interlaced_renderer(p);
	newframe_init_sprite(p);
	while (x < p->w)
	{
		prepare_new_ray(p, &f, x);
		perform_digital_differential_analysis(p, &f);
		get_wall_data(p, &f, x);
		draw_stripe(p, &f, x);
		x += (1 + p->interlace);
	}
	refreshmap(p);
	if (BONUS && p->health > 0)
		perform_sprites_interactions(p, 0);
	move_player(p);
	if (BONUS)
		draw_bonus_to_img(p);
	mlx_put_image_to_window(p->vars.mlx, p->vars.win, p->img.img, 0, 0);
	if (BONUS)
		draw_bonus_to_window(p);
	return (1);
}
