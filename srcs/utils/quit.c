/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:05:39 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 16:15:59 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_bonus_images_hud(t_params *params)
{
	if (params->key_y.width != 0)
		mlx_destroy_image(params->vars.mlx, params->key_y.img);
	if (params->key_r.width != 0)
		mlx_destroy_image(params->vars.mlx, params->key_r.img);
	if (params->crosshair.width != 0)
		mlx_destroy_image(params->vars.mlx, params->crosshair.img);
	if (params->weapf.width != 0)
		mlx_destroy_image(params->vars.mlx, params->weapf.img);
	if (params->weap.width != 0)
		mlx_destroy_image(params->vars.mlx, params->weap.img);
	if (params->hud.width != 0)
		mlx_destroy_image(params->vars.mlx, params->hud.img);
}

static void	destroy_bonus_images_sprite(t_params *params)
{
	if (params->healths.width != 0)
		mlx_destroy_image(params->vars.mlx, params->healths.img);
	if (params->nightv.width != 0)
		mlx_destroy_image(params->vars.mlx, params->nightv.img);
	if (params->spritesolid.width != 0)
		mlx_destroy_image(params->vars.mlx, params->spritesolid.img);
	if (params->skybox.width != 0)
		mlx_destroy_image(params->vars.mlx, params->skybox.img);
	if (params->spritelive.width != 0)
		mlx_destroy_image(params->vars.mlx, params->spritelive.img);
	if (params->spritedead.width != 0)
		mlx_destroy_image(params->vars.mlx, params->spritedead.img);
	if (params->spriteexp.width != 0)
		mlx_destroy_image(params->vars.mlx, params->spriteexp.img);
	if (params->font.width != 0)
		mlx_destroy_image(params->vars.mlx, params->font.img);
	if (params->gunspr.width != 0)
		mlx_destroy_image(params->vars.mlx, params->gunspr.img);
	if (params->ammob.width != 0)
		mlx_destroy_image(params->vars.mlx, params->ammob.img);
	if (params->ammos.width != 0)
		mlx_destroy_image(params->vars.mlx, params->ammos.img);
	if (params->healthb.width != 0)
		mlx_destroy_image(params->vars.mlx, params->healthb.img);
	destroy_bonus_images_hud(params);
}

void		destroy_bonus_images(t_params *params)
{
	if (params->walltex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->walltex.img);
	if (params->limitstex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->limitstex.img);
	if (params->infloortex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->infloortex.img);
	if (params->floortex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->floortex.img);
	if (params->pushwall.width != 0)
		mlx_destroy_image(params->vars.mlx, params->pushwall.img);
	if (params->doortex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doortex.img);
	if (params->doortex_y.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doortex_y.img);
	if (params->doortex_r.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doortex_r.img);
	if (params->doorframetex_y.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doorframetex_y.img);
	if (params->doorframetex_r.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doorframetex_r.img);
	if (params->doorframetex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->doorframetex.img);
	if (params->cylindtex.width != 0)
		mlx_destroy_image(params->vars.mlx, params->cylindtex.img);
	destroy_bonus_images_sprite(params);
}

void		quit_msg(t_params *params, char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	quit(params);
}

void		quit(t_params *params)
{
	destroy_images(params);
	if (params->parser & PARSER_IMG)
		mlx_destroy_image(params->vars.mlx, params->img.img);
	if (params->parser & PARSER_MAP)
		free_tab(params->map.tab, params->map.size.y);
	free_allocated_tables(params);
	if (BONUS)
		destroy_bonus_images(params);
	if (!(params->captureframe) || (params->parser & PARSER_WIN))
		mlx_destroy_window(params->vars.mlx, params->vars.win);
	free(params->vars.mlx);
	exit(EXIT_SUCCESS);
}
