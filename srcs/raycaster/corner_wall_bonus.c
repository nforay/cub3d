/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corner_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:41:36 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 21:41:02 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_corner_wall_hit(t_params *params, t_frame *f)
{
	f->line.x = (double)f->mapx;
	f->line.y = (double)f->mapy;
	if (ft_toupper(f->raytex) == 'B')
		f->point = lineintersect(params, f->raydir, f->line, -1);
	else
		f->point = lineintersect(params, f->raydir, f->line, 1);
	if (f->point.x >= f->mapx && f->point.x <= f->mapx + 1 &&
		f->point.y >= f->mapy && f->point.y <= f->mapy + 1)
	{
		f->hit = 1;
		f->side = 2;
		f->perpwalldist = ((f->point.x - params->pos.x + f->point.y -
			params->pos.y) / 2) / ((f->raydir.x + f->raydir.y) / 2);
	}
}
