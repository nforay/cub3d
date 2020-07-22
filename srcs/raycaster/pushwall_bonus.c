/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushwall_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:14:12 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 18:38:46 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_pushwall_hit(t_params *params, t_frame *f)
{
	if (f->side == 1 && f->sidedisty - (f->deltadisty *
		(1 - door_offset(&params->map, f->mapx, f->mapy))) < f->sidedistx)
	{
		f->hit = 1;
		f->wallyoffset = door_offset(&params->map, f->mapx, f->mapy) * f->stepy;
	}
	else if (f->side == 0 && f->sidedistx - (f->deltadistx *
		(1 - door_offset(&params->map, f->mapx, f->mapy))) < f->sidedisty)
	{
		f->hit = 1;
		f->wallxoffset = door_offset(&params->map, f->mapx, f->mapy) * f->stepx;
	}
}
