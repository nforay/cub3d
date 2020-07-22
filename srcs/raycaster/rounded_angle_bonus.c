/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounded_angle_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:20:27 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 18:32:17 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rounded_top_left_hit(t_params *params, t_frame *f)
{
	f->center.x = f->mapx + 1;
	f->center.y = f->mapy + 1;
	if (raycircleangle(params->pos, f->raydir, f->center, &f->intersect) != 0)
	{
		f->hit = 1;
		if ((int)f->intersect.x == f->mapx && (int)f->intersect.y == f->mapy)
		{
			f->side = 3;
			f->perpwalldist = ((f->intersect.x - params->pos.x + f->intersect.y
				- params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
			f->wallx = ((atan2(f->center.y - f->intersect.y, f->center.x -
				f->intersect.x) + M_PI) / (M_PI * 2)) * 2;
			f->wallx += f->wallx;
		}
	}
}

void	rounded_bot_left_hit(t_params *params, t_frame *f)
{
	f->center.x = f->mapx + 1;
	f->center.y = f->mapy;
	if (raycircleangle(params->pos, f->raydir, f->center, &f->intersect) != 0)
	{
		f->hit = 1;
		if ((int)f->intersect.x == f->mapx && (int)f->intersect.y == f->mapy)
		{
			f->side = 3;
			f->perpwalldist = ((f->intersect.x - params->pos.x + f->intersect.y
				- params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
			f->wallx = fabs(atan2(f->center.y - f->intersect.y, f->center.x -
				f->intersect.x) / (M_PI * 2)) * 2;
			f->wallx += f->wallx;
		}
	}
}

void	rounded_top_right_hit(t_params *params, t_frame *f)
{
	f->center.x = f->mapx;
	f->center.y = f->mapy + 1;
	if (raycircleangle(params->pos, f->raydir, f->center, &f->intersect) != 0)
	{
		f->hit = 1;
		if ((int)f->intersect.x == f->mapx && (int)f->intersect.y == f->mapy)
		{
			f->side = 3;
			f->perpwalldist = ((f->intersect.x - params->pos.x + f->intersect.y
				- params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
			f->wallx = ((atan2(f->center.y - f->intersect.y, f->center.x -
				f->intersect.x)) / (M_PI * 2) * 2);
			f->wallx = fabs(f->wallx - 1.5) * 2;
		}
	}
}

void	rounded_bot_right_hit(t_params *params, t_frame *f)
{
	f->center.x = f->mapx;
	f->center.y = f->mapy;
	if (raycircleangle(params->pos, f->raydir, f->center, &f->intersect) != 0)
	{
		f->hit = 1;
		if ((int)f->intersect.x == f->mapx && (int)f->intersect.y == f->mapy)
		{
			f->side = 3;
			f->perpwalldist = ((f->intersect.x - params->pos.x + f->intersect.y
				- params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
			f->wallx = ((atan2(f->center.y - f->intersect.y, f->center.x -
				f->intersect.x) + M_PI) / (M_PI * 2)) * 2;
			f->wallx += f->wallx;
		}
	}
}

void	check_rounded_angle_hit(t_params *params, t_frame *f)
{
	if (ft_toupper(f->raytex) == 'H')
		rounded_top_left_hit(params, f);
	else if (ft_toupper(f->raytex) == 'I')
		rounded_bot_left_hit(params, f);
	else if (ft_toupper(f->raytex) == 'J')
		rounded_top_right_hit(params, f);
	else if (ft_toupper(f->raytex) == 'K')
		rounded_bot_right_hit(params, f);
}
