/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_custom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:34:53 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 20:15:01 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		getcolor(t_color color)
{
	int result;

	result = (color.r << 16);
	result += (color.g << 8);
	result += color.b;
	return (result);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_bl(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (color & 0xFFFFFFFF)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

int		getpixelcolor(t_image *img, int x, int y)
{
	if (!img->width || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width)) * (img->bpp / 8))));
}

int		getwallpixelcolor(t_params *p, t_image *img, t_frame *f, t_wall *w)
{
	int x;
	int y;

	if (!img->width || !img->height)
	{
		if (f->drawstart > (p->h / 2))
			return (getcolor(p->floor));
		else
			return (getcolor(p->ceil));
	}
	x = abs(w->tex_y);
	y = abs(w->tex_x);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width)) * (img->bpp / 8))));
}
