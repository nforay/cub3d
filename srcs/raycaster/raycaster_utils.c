/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:44:04 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 17:19:57 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_bonus_to_img(t_params *params)
{
	if (params->debug % 2 == 0 && params->w >= 200 && params->h >= 200)
	{
		draw_square(params, 50, 50, 100);
		draw_circle(&params->img,
			50 + (100 * (params->pos.y - (int)params->pos.y)),
			50 + (100 * (params->pos.x - (int)params->pos.x)), 18);
		ft_printnbr_rtl(params->framecount, params->w - 50, 40, params);
	}
	if (params->w >= 150 && params->h >= 50)
	{
		ft_printnbr_rtl(params->health, 120, params->h - 30, params);
		ft_printnbr_rtl(params->ammo, 50, params->h - 30, params);
	}
}

void	prepare_new_ray(t_params *p, t_frame *f, int x)
{
	ft_memset(f, 0, sizeof(t_frame));
	f->camerax = 2 * x / (double)p->w - 1;
	f->raydir.x = p->dir.x + p->plane.x * f->camerax;
	f->raydir.y = p->dir.y + p->plane.y * f->camerax;
	f->mapx = p->pos.x < 0 ? (-1) + (int)p->pos.x : (int)p->pos.x;
	f->mapy = p->pos.y < 0 ? (-1) + (int)p->pos.y : (int)p->pos.y;
	f->deltadistx = fabs(1 / f->raydir.x);
	f->deltadisty = fabs(1 / f->raydir.y);
	f->skyx = fabs(atan2(f->raydir.y, f->raydir.x) * 180 / M_PI - 180) / 360;
	get_step_and_sidedist(p, f);
}

void	get_wall_data(t_params *params, t_frame *f, int x)
{
	if (f->side == 0)
		f->perpwalldist = (f->mapx - params->pos.x + f->wallxoffset +
			(1 - f->stepx) / 2) / f->raydir.x;
	else if (f->side == 1)
		f->perpwalldist = (f->mapy - params->pos.y + f->wallyoffset +
			(1 - f->stepy) / 2) / f->raydir.y;
	if (!BONUS && f->raytex == 'Z')
		f->perpwalldist = 1;
	params->zbuffer[x] = (double)f->perpwalldist;
	f->lineheight = (int)(params->h / f->perpwalldist);
	f->drawstart = (int)(-f->lineheight / 2 + params->h / 2);
	f->drawstart = f->drawstart < 0 ? 0 : f->drawstart;
	f->drawstart = (f->drawstart > params->h) ? params->h : f->drawstart;
	f->drawend = (f->lineheight / 2 + params->h / 2);
	f->drawend = (f->drawend > params->h) ? params->h : f->drawend;
	f->drawend = (f->drawend < 0) ? 0 : f->drawend;
	if (f->side == 0)
		f->wallx = params->pos.y + f->perpwalldist * f->raydir.y;
	else if (f->side <= 2)
		f->wallx = params->pos.x + f->perpwalldist * f->raydir.x;
	f->wallx -= (int)f->wallx;
	if (char_in_str("GLM", ft_toupper(f->raytex)))
		f->wallx += door_offset(&params->map, f->mapx, f->mapy);
}

void	draw_stripe(t_params *params, t_frame *f, int x)
{
	draw_sprite_bis(params, x);
	if (params->debug % 2 == 0)
		f->color = RED;
	if (BONUS && f->drawend < params->h && params->infloortex.height != 0)
		draw_floor(params, x, f->drawend + 1);
	else if (f->drawend < params->h)
		verline_floor(params, x, f->drawend, params->h);
	if (BONUS && f->drawstart > 0 && params->skybox.height != 0)
		draw_sky(params, x, 0, *f);
	else if (f->drawstart > 0)
		verline_ceil(params, x, 0, f->drawstart);
	if (!BONUS || (BONUS && params->zbuffer[x] < (params->shadedist * 20)))
		draw_wall(params, x, f);
	else
		verline(params, x, *f);
}
