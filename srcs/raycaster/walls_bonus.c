/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:49:19 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 01:59:35 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	shade_wall_color(t_params *p, t_wall *w, t_frame f, int x)
{
	if (f.raytex == 'Z')
		return ;
	if (p->weaponcd > (int)(p->weaponbasecd * 0.75) &&
		p->zbuffer[x] < p->shadefiring)
		w->color = shadefiringcolor(p, p->zbuffer[x], w->color);
	if (p->zbuffer[x] > p->shadedist && ft_toupper(f.raytex) != 'Z')
		w->color = shadecolor(p, p->zbuffer[x], w->color);
	else if (f.raytex != 'Z' && p->zbuffer[x] < p->shadedist)
		w->color = shadecolor(p, p->shadedist, w->color);
}

int		raycircle(t_coord p1, t_coord dp, t_coord sc, t_coord *intersect)
{
	double a;
	double b;
	double c;
	double bb4ac;

	a = dp.x * dp.x + dp.y * dp.y;
	b = 2 * (dp.x * (p1.x - sc.x) + dp.y * (p1.y - sc.y));
	c = sc.x * sc.x + sc.y * sc.y;
	c += p1.x * p1.x + p1.y * p1.y;
	c -= 2 * (sc.x * p1.x + sc.y * p1.y);
	c -= 0.45 * 0.45;
	bb4ac = b * b - 4 * a * c;
	if (bb4ac < 0)
	{
		intersect->x = 0;
		intersect->y = 0;
		return (0);
	}
	bb4ac = (-b - sqrt(bb4ac)) / (2 * a);
	intersect->x = p1.x + dp.x * bb4ac;
	intersect->y = p1.y + dp.y * bb4ac;
	return (1);
}

int		raycircleangle(t_coord p1, t_coord dp, t_coord sc, t_coord *intersect)
{
	double a;
	double b;
	double c;
	double bb4ac;

	a = dp.x * dp.x + dp.y * dp.y;
	b = 2 * (dp.x * (p1.x - sc.x) + dp.y * (p1.y - sc.y));
	c = sc.x * sc.x + sc.y * sc.y;
	c += p1.x * p1.x + p1.y * p1.y;
	c -= 2 * (sc.x * p1.x + sc.y * p1.y);
	c -= 1 * 1;
	bb4ac = b * b - 4 * a * c;
	if (bb4ac < 0)
	{
		intersect->x = 0;
		intersect->y = 0;
		return (0);
	}
	bb4ac = (-b - sqrt(bb4ac)) / (2 * a);
	intersect->x = p1.x + dp.x * bb4ac;
	intersect->y = p1.y + dp.y * bb4ac;
	return (1);
}

t_coord	lineintersect(t_params *params, t_coord raydir, t_coord map, int side)
{
	t_coord	a;
	t_coord	b;
	t_coord	c;
	t_coord tmp;

	a.x = raydir.y;
	b.x = -raydir.x;
	c.x = a.x * params->pos.x + b.x * params->pos.y;
	a.y = side;
	b.y = -1;
	c.y = a.y * map.x + b.y * ((side < 0) ? map.y + 1 : map.y);
	tmp.x = (b.y * c.x - b.x * c.y) / (a.x * b.y - a.y * b.x);
	tmp.y = (a.x * c.y - a.y * c.x) / (a.x * b.y - a.y * b.x);
	return (tmp);
}
