/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:38:11 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 18:42:11 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_column_hit(t_params *params, t_frame *f)
{
	f->center.x = f->mapx + 0.5;
	f->center.y = f->mapy + 0.5;
	if (raycircle(params->pos, f->raydir, f->center, &f->intersect) != 0)
	{
		f->hit = 1;
		f->side = 3;
		f->perpwalldist = ((f->intersect.x - params->pos.x + f->intersect.y -
			params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
		f->wallx = atan2((f->center.y - f->intersect.y),
			(f->center.x - f->intersect.x)) * 180 / M_PI;
		f->wallx = ((f->wallx > 90) ? 450 - f->wallx : 90 - f->wallx);
		f->wallx /= 360;
	}
}
