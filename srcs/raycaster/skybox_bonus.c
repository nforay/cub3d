/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:45:35 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 17:15:08 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sky(t_params *p, int x, int drawstart, t_frame f)
{
	double	step;
	int		tex_x;
	double	texpos;
	int		tex_y;

	tex_x = p->skybox.width;
	step = p->skybox.width / (double)(p->h / 2);
	texpos = p->skybox.width;
	tex_y = (int)(f.skyx * (double)(p->skybox.height - 1));
	if (tex_y < 1)
		tex_y = 1;
	while (drawstart < f.drawstart)
	{
		tex_x = (int)texpos;
		texpos = texpos - step;
		if (!(ft_bufferstate(p, x, drawstart)))
			my_mlx_pixel_put(&p->img, x, drawstart, greyscale(p,
				getpixelcolor(&p->skybox, tex_x, tex_y)));
		else if (!(p->debug % 2) && x % 2 && drawstart % 2)
			my_mlx_pixel_put(&p->img, x, drawstart, SKY);
		drawstart++;
	}
}
