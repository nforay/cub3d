/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:51:58 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 23:45:19 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_floor_tex(t_params *params, t_floor *f)
{
	t_image	*img;

	img = &params->floortex;
	if (f->celly >= 0 && f->celly < params->map.size.y &&
			(params->map.tab[f->celly][f->cellx] == '8' ||
			params->map.tab[f->celly][f->cellx] == '0' ||
			params->map.tab[f->celly][f->cellx] >= 'a'))
		img = &params->infloortex;
	f->img = img;
	f->tx = (int)(img->width * (f->floorx - f->cellx));
	f->ty = (int)(img->height * (f->floory - f->celly));
}

void	get_floor_data(t_params *params, t_floor *f, int x, int y)
{
	t_coord	delta;

	f->raydirx0 = params->dir.x - params->plane.x;
	f->raydiry0 = params->dir.y - params->plane.y;
	f->raydirx1 = params->dir.x + params->plane.x;
	f->raydiry1 = params->dir.y + params->plane.y;
	f->p = y - params->h / 2;
	f->posz = 0.5 * params->h;
	f->rowdistance = f->posz / f->p;
	f->stepx = f->rowdistance * (f->raydirx1 - f->raydirx0) / params->w;
	f->stepy = f->rowdistance * (f->raydiry1 - f->raydiry0) / params->w;
	f->floorx = params->pos.x + f->rowdistance * f->raydirx0 + f->stepx * x;
	f->floory = params->pos.y + f->rowdistance * f->raydiry0 + f->stepy * x;
	f->cellx = (int)(f->floorx);
	f->celly = (int)(f->floory);
	get_floor_tex(params, f);
	f->floorx += f->stepx;
	f->floory += f->stepy;
	delta.x = fabs(f->floorx - params->pos.x);
	delta.y = fabs(f->floory - params->pos.y);
	f->dist = sqrt(delta.x * delta.x + delta.y * delta.y);
	if (params->debug % 2)
		f->color = BLACK;
	else
		f->color = GREEN;
}

int		tile_has_ceiling(t_params *params, t_floor *f, int x, int y)
{
	if (f->celly >= 0 && f->celly < params->map.size.y &&
				!(ft_bufferstate(params, x, (params->h - y))) &&
				(params->map.tab[f->celly][f->cellx] == '0' ||
				params->map.tab[f->celly][f->cellx] >= 'a'))
		return (1);
	return (0);
}

void	shade_and_draw_floor(t_params *params, t_floor f, int x, int y)
{
	if (params->weaponcd > (int)(params->weaponbasecd * 0.75) &&
			f.dist < params->shadefiring)
		f.color = shadefiringcolor(params, f.dist, f.color);
	if (f.dist > params->shadedist)
		f.color = shadecolor(params, f.dist, f.color);
	else
		f.color = shadecolor(params, params->shadedist, f.color);
	if (!(ft_bufferstate(params, x, y)))
		my_mlx_pixel_put(&params->img, x, y, f.color);
	else if (!(params->debug % 2) && x % 2 && y % 2)
		my_mlx_pixel_put(&params->img, x, y, GREEN);
	if (tile_has_ceiling(params, &f, x, y))
	{
		my_mlx_pixel_put(&params->img, x, params->h - y, f.color);
		ft_writebuffer(params, x, params->h - y);
	}
}

void	draw_floor(t_params *params, int x, int drawend)
{
	int		y;
	t_floor	f;

	y = drawend;
	while (y < params->h)
	{
		get_floor_data(params, &f, x, y);
		if (f.dist < (params->shadedist * 20))
		{
			f.color = getpixelcolor(f.img, f.tx, f.ty);
			if (y >= drawend)
				shade_and_draw_floor(params, f, x, y);
		}
		else if (y >= drawend)
		{
			if (!(ft_bufferstate(params, x, y)))
				my_mlx_pixel_put(&params->img, x, y, f.color);
			if (tile_has_ceiling(params, &f, x, y))
			{
				my_mlx_pixel_put(&params->img, x, params->h - y, f.color);
				ft_writebuffer(params, x, params->h - y);
			}
		}
		y++;
	}
}
