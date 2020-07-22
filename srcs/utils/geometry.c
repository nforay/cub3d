/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:36:00 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 17:19:57 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_square(t_params *params, int x, int y, int len)
{
	t_icoord	orig;

	orig.x = x;
	orig.y = y;
	while ((x - orig.x) < len)
	{
		my_mlx_pixel_put(&params->img, x, orig.y, WHITE);
		my_mlx_pixel_put(&params->img, x, orig.y + len, WHITE);
		my_mlx_pixel_put(&params->img, orig.x, y, WHITE);
		my_mlx_pixel_put(&params->img, orig.x + len, y, WHITE);
		x++;
		y++;
	}
}

void	verline_floor(t_params *p, int x, int y, int drawend)
{
	int	color;

	color = getcolor(p->floor);
	while (y < drawend)
	{
		if (!(ft_bufferstate(p, x, y)))
			my_mlx_pixel_put(&p->img, x, y, color);
		y++;
	}
}

void	verline_ceil(t_params *p, int x, int y, int drawend)
{
	int	color;

	color = getcolor(p->ceil);
	while (y < drawend)
	{
		if (!(ft_bufferstate(p, x, y)))
			my_mlx_pixel_put(&p->img, x, y, color);
		y++;
	}
}

void	verline(t_params *params, int x, t_frame f)
{
	while (f.drawstart <= f.drawend)
	{
		if (!(ft_bufferstate(params, x, f.drawstart)))
			my_mlx_pixel_put(&params->img, x, f.drawstart, f.color);
		f.drawstart++;
	}
}

void	draw_circle(t_image *img, int x, int y, int r)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		my_mlx_pixel_put(img, x + x1, y + y1, WHITE);
		i += 0.1;
	}
}
