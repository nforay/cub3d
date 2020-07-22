/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 03:04:22 by nforay            #+#    #+#             */
/*   Updated: 2020/07/04 19:39:05 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	greyscale(t_params *p, int color)
{
	int r;
	int	g;
	int	b;
	int grey;

	if (!(p->greyscale))
		return (color);
	r = ((color >> 16) & 0xFF);
	g = ((color >> 8) & 0xFF);
	b = (color & 0xFF);
	grey = (int)((r + g + b) / 3);
	color = (grey << 16);
	color += (grey << 8);
	color += grey;
	return (color);
}

int	shadedamagecolor(t_params *p, double dist, int color)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF);
	r *= (1 / dist * p->shadedist) > 1 ? 3 : (1 / dist * p->shadedist) * 2;
	g = ((color >> 8) & 0xFF);
	g *= (1 / dist * p->shadedist) > 1 ? 1 : (1 / dist * p->shadedist);
	b = (color & 0xFF);
	b *= (1 / dist * p->shadedist) > 1 ? 1 : (1 / dist * p->shadedist);
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	if (p->greyscale)
		return (greyscale(p, color));
	else
		return (color);
}

int	shadecolor_nodist(t_params *p, int color)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * p->shadecol.r;
	g = ((color >> 8) & 0xFF) * p->shadecol.g;
	b = (color & 0xFF) * p->shadecol.b;
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	if (p->greyscale)
		return (greyscale(p, color));
	else
		return (color);
}

int	shadecolor(t_params *p, double dist, int color)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * (1 / dist * p->shadedist) * p->shadecol.r;
	g = ((color >> 8) & 0xFF) * (1 / dist * p->shadedist) * p->shadecol.g;
	b = (color & 0xFF) * (1 / dist * p->shadedist) * p->shadecol.b;
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	if (p->greyscale)
		return (greyscale(p, color));
	else
		return (color);
}

int	shadefiringcolor(t_params *p, double dist, int color)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * (1 / dist * p->shadefiring);
	g = ((color >> 8) & 0xFF) * (1 / dist * p->shadefiring);
	b = (color & 0xFF) * (1 / dist * p->shadefiring);
	r = ((r > 255) ? 255 : r);
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	if (p->greyscale)
		return (greyscale(p, color));
	else
		return (color);
}
