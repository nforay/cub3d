/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_dda.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:35:46 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 20:25:09 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		get_step_and_sidedist(t_params *params, t_frame *f)
{
	if (f->raydir.x < 0)
	{
		f->stepx = -1;
		f->sidedistx = (params->pos.x - f->mapx) * f->deltadistx;
	}
	else
	{
		f->stepx = 1;
		f->sidedistx = (f->mapx + 1.0 - params->pos.x) * f->deltadistx;
	}
	if (f->raydir.y < 0)
	{
		f->stepy = -1;
		f->sidedisty = (params->pos.y - f->mapy) * f->deltadisty;
	}
	else
	{
		f->stepy = 1;
		f->sidedisty = (f->mapy + 1.0 - params->pos.y) * f->deltadisty;
	}
}

static void	get_next_square(t_params *params, t_frame *f)
{
	if (f->sidedistx < f->sidedisty)
	{
		f->sidedistx += f->deltadistx;
		f->mapx += f->stepx;
		f->side = 0;
	}
	else
	{
		f->sidedisty += f->deltadisty;
		f->mapy += f->stepy;
		f->side = 1;
	}
	if (((f->mapx < 0 && f->stepx < 0) || (f->mapy < 0 && f->stepy < 0) ||
		((f->mapx >= params->map.size.x) && f->stepx >= 0) ||
		((f->mapy >= params->map.size.y) && f->stepy >= 0)))
	{
		f->raytex = 'Z';
		f->hit = 1;
	}
	else if (f->mapx >= 0 && f->mapy >= 0 && f->mapx < params->map.size.x &&
			f->mapy < params->map.size.y)
		f->raytex = params->map.tab[f->mapy][f->mapx];
}

static void	check_ray_hit(t_params *params, t_frame *f)
{
	if (BONUS)
	{
		if (char_in_str("GLM", ft_toupper(f->raytex)) &&
			door_state(params, f->mapx, f->mapy) != 2)
			check_door_hit(params, f);
		else if (ft_toupper(f->raytex) == 'D' &&
				door_state(params, f->mapx, f->mapy) < 2)
			check_pushwall_hit(params, f);
		else if (char_in_str("HIJK", ft_toupper(f->raytex)))
			check_rounded_angle_hit(params, f);
		else if (ft_toupper(f->raytex) == 'A')
			check_column_hit(params, f);
		else if (char_in_str("BC", ft_toupper(f->raytex)))
			check_corner_wall_hit(params, f);
		else if (!is_interactible(f->raytex) && is_interior(f->raytex))
			f->hit = 1;
	}
	else if (!is_interactible(f->raytex) && is_interior(f->raytex))
		f->hit = 1;
	if (BONUS && !is_interactible(f->raytex))
		merge_doorframe(params, f);
}

void		perform_digital_differential_analysis(t_params *params, t_frame *f)
{
	while (f->hit == 0)
	{
		get_next_square(params, f);
		f->angleside = 0;
		if (f->raytex != '0')
			check_ray_hit(params, f);
	}
}
