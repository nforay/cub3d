/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:56:49 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 18:15:06 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_interactible(char c)
{
	if (char_in_str("DGLM", ft_toupper(c)))
		return (1);
	return (0);
}

void	merge_doorframe(t_params *params, t_frame *f)
{
	char	c;
	char	d;

	if (f->side == 1)
	{
		c = ft_toupper(params->map.tab[f->mapy - f->stepy][f->mapx]);
		if (c == 'G')
			f->raytex = '7';
		else if (c == 'L')
			f->raytex = ':';
		else if (c == 'M')
			f->raytex = ';';
	}
	else if (f->side == 0)
	{
		d = ft_toupper(params->map.tab[f->mapy][f->mapx - f->stepx]);
		if (d == 'G')
			f->raytex = '7';
		else if (d == 'L')
			f->raytex = ':';
		else if (d == 'M')
			f->raytex = ';';
	}
}

void	door_hit_x(t_params *params, t_frame *f)
{
	f->wallxoffset = 0.5 * f->stepx;
	f->perpwalldist = (f->mapx - params->pos.x + f->wallxoffset +
		(1 - f->stepx) / 2) / f->raydir.x;
	f->wallx = params->pos.y + f->perpwalldist * f->raydir.y;
	f->wallx -= (int)f->wallx;
	if (f->sidedistx - (f->deltadistx / 2) < f->sidedisty)
	{
		if (1 - f->wallx <= door_offset(&params->map, f->mapx, f->mapy))
		{
			f->hit = 0;
			f->wallxoffset = 0;
		}
	}
	else
	{
		f->mapy += f->stepy;
		f->side = 1;
		f->raytex = '7';
		f->wallxoffset = 0;
	}
}

void	door_hit_y(t_params *params, t_frame *f)
{
	f->wallyoffset = 0.5 * f->stepy;
	f->perpwalldist = (f->mapy - params->pos.y + f->wallyoffset +
		(1 - f->stepy) / 2) / f->raydir.y;
	f->wallx = params->pos.x + f->perpwalldist * f->raydir.x;
	f->wallx -= (int)f->wallx;
	if (f->sidedisty - (f->deltadisty / 2) < f->sidedistx)
	{
		if (1 - f->wallx <= door_offset(&params->map, f->mapx, f->mapy))
		{
			f->hit = 0;
			f->wallyoffset = 0;
		}
	}
	else
	{
		f->mapx += f->stepx;
		f->side = 0;
		f->raytex = '7';
		f->wallyoffset = 0;
	}
}

void	check_door_hit(t_params *params, t_frame *f)
{
	f->hit = 1;
	if (f->side == 1)
	{
		door_hit_y(params, f);
	}
	else
	{
		door_hit_x(params, f);
	}
}
