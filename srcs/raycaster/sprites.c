/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:53:25 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 01:58:28 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_sprite_draw_limits(t_params *p, t_sprite *this)
{
	this->drawstartx = -this->spritewidth / 2 + this->spritescreenx;
	this->drawendx = this->spritewidth / 2 + this->spritescreenx;
	this->drawstarty = -this->spriteheight / 2 + p->h / 2;
	this->drawendy = this->spriteheight / 2 + p->h / 2;
	if (this->drawstartx < 0)
		this->drawstartx = 0;
	if (this->drawendx >= p->w)
		this->drawendx = p->w;
	if (this->drawstarty < 0)
		this->drawstarty = 0;
	if (this->drawendy >= p->h)
		this->drawendy = p->h;
}

void		get_sprite_pos(t_params *p)
{
	t_sprite	*this;
	double		invdet;
	int			i;

	i = 0;
	while (i < p->map.n_sprite)
	{
		this = &p->map.sprite[p->map.s_order[i]];
		if (p->map.s_dist[i] < p->shadedist * 150)
		{
			this->spritex = this->x - p->pos.x;
			this->spritey = this->y - p->pos.y;
			invdet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
			this->transformx = invdet * (p->dir.y * this->spritex - p->dir.x *
				this->spritey);
			this->transformy = invdet * (-p->plane.y * this->spritex +
				p->plane.x * this->spritey);
			this->spritescreenx = (int)((p->w / 2) *
				(1 + this->transformx / this->transformy));
			this->spritewidth = abs((int)(p->h / (this->transformy)));
			this->spriteheight = abs((int)(p->h / (this->transformy)));
			get_sprite_draw_limits(p, this);
		}
		i++;
	}
}

t_image		*get_sprite_img(t_params *p, t_sprite *sprite)
{
	if (sprite->texture == '2')
		return (&p->sprite);
	else if (BONUS)
		return (get_sprite_img_bonus(p, sprite));
	else
		return (&p->sprite);
}

void		put_sprite_to_img(t_params *p, t_spr_cast *s, int x, int y)
{
	int	col;
	int	d;

	while (y < s->curr->drawendy)
	{
		s->curr->active = (ft_toupper(s->curr->texture) == 'O' ? 1 : 0);
		if (!(ft_bufferstate(p, x, y)))
		{
			d = y * 256 - p->h * 128 + s->curr->spriteheight * 128;
			s->tex.y = ((d * s->img->height) / s->curr->spriteheight) / 256;
			col = getpixelcolor(s->img, s->tex.y, s->tex.x);
			if (((col & 0xFFFF00FF) != 0) || !(col & 0xFF00FF00))
			{
				my_mlx_pixel_put(&p->img, x, y, shade_sprite_color(p, *s, col));
				if (BONUS && sprite_hitscan(p, x, y))
					s->curr->hit = 2;
				ft_writebuffer(p, x, y);
			}
			else if (!(p->debug % 2) && !(x % 2) && !(y % 2))
				my_mlx_pixel_put(&p->img, x, y, BLUE);
		}
		else if (!(p->debug % 2) && !(x % 2) && !(y % 2))
			my_mlx_pixel_put(&p->img, x, y, BLUE);
		y++;
	}
}

void		draw_sprite_bis(t_params *p, int x)
{
	t_spr_cast	s;
	int			i;

	i = 0;
	while (i < p->map.n_sprite)
	{
		s.curr = &p->map.sprite[p->map.s_order[i]];
		if (((s.dist = p->map.s_dist[i]) < p->shadedist * 30) &&
			(s.curr->health != 0 || ft_toupper(s.curr->texture) == 'O') &&
			(x >= s.curr->drawstartx && x < s.curr->drawendx) &&
			(s.curr->transformy > 0.03 && s.curr->transformy < p->zbuffer[x]) &&
			(s.dist >= 0.5 || (s.curr->health != 0 ||
			ft_toupper(s.curr->texture) == 'O')))
		{
			s.img = get_sprite_img(p, s.curr);
			s.tex.x = (int)(256 * (x - (-s.curr->spritewidth / 2 +
			s.curr->spritescreenx)) * s.img->width / s.curr->spritewidth) / 256;
			put_sprite_to_img(p, &s, x, s.curr->drawstarty);
		}
		i++;
	}
}
