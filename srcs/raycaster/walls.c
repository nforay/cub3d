/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:47:58 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 17:41:20 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_image	*get_side_tex(t_params *params, t_frame *f)
{
	if (f->side == 0 && f->raydir.x < 0)
		return (&params->east);
	else if (f->side == 0)
		return (&params->west);
	if (f->side == 1 && f->raydir.y < 0)
		return (&params->south);
	else
		return (&params->north);
}

t_image	*get_wall_tex_next(t_params *params, t_frame *f)
{
	if (ft_toupper(f->raytex) == 'M')
		return (&params->doortex_r);
	else if (ft_toupper(f->raytex) == ':')
		return (&params->doorframetex_y);
	else if (ft_toupper(f->raytex) == 'D')
		if (params->pushwall.height != 0)
			return (&params->pushwall);
		else
			return (get_side_tex(params, f));
	else if (ft_toupper(f->raytex) == ';')
		return (&params->doorframetex_r);
	else
		return (&params->walltex);
}

t_image	*get_wall_tex(t_params *params, t_frame *f)
{
	if (f->raytex == '1')
		return (get_side_tex(params, f));
	else if (f->raytex == '3')
		return (&params->north);
	else if (f->raytex == '4')
		return (&params->south);
	else if (f->raytex == '5')
		return (&params->east);
	else if (f->raytex == '6')
		return (&params->west);
	else if (ft_toupper(f->raytex) == '7')
		return (&params->doorframetex);
	else if (ft_toupper(f->raytex) == 'A')
		return (&params->cylindtex);
	else if (f->raytex == 'Z')
		return (&params->limitstex);
	else if (ft_toupper(f->raytex) == 'G')
		return (&params->doortex);
	else if (ft_toupper(f->raytex) == 'L')
		return (&params->doortex_y);
	else
		return (get_wall_tex_next(params, f));
}

void	get_wall_values(t_wall *w, t_image *img, t_frame *f, t_params *params)
{
	w->step = 1.0 * img->width / f->lineheight;
	w->texpos = (f->drawstart - params->h / 2 + f->lineheight / 2) * w->step;
	w->tex_x = (int)(f->wallx * (double)img->width);
	if (f->side == 0 && f->raydir.x > 0 &&
			!(char_in_str("GLM", ft_toupper(f->raytex))))
		w->tex_x = img->width - w->tex_x - 1;
	if (f->side == 1 && f->raydir.y < 0 &&
			!(char_in_str("GLM", ft_toupper(f->raytex))))
		w->tex_x = img->width - w->tex_x - 1;
	if (ft_toupper(f->raytex) == 'A')
	{
		w->tex_x = (int)(f->wallx * (img->height - 1));
		w->tex_x += params->framecount + 20;
		if (w->tex_x >= img->height)
			w->tex_x -= (int)(w->tex_x / img->height) * img->height;
	}
	if (BONUS && f->raytex == 'Z')
	{
		w->tex_x += params->framecount;
		if (w->tex_x > img->width)
			w->tex_x -= (int)(w->tex_x / img->width) * img->width;
	}
}

void	draw_wall(t_params *params, int x, t_frame *f)
{
	t_image	*img;
	t_wall	w;

	img = get_wall_tex(params, f);
	get_wall_values(&w, img, f, params);
	while (f->drawstart <= f->drawend)
	{
		if (ft_bufferstate(params, x, f->drawstart))
		{
			w.texpos += w.step;
			if (!params->debug && (x % 2) && (f->drawstart % 2))
				my_mlx_pixel_put(&params->img, x, f->drawstart, YELLOW);
			f->drawstart++;
			continue;
		}
		w.tex_y = (int)w.texpos;
		if (BONUS)
			w.color = getpixelcolor(img, w.tex_y, w.tex_x);
		else
			w.color = getwallpixelcolor(params, img, f, &w);
		if (BONUS)
			shade_wall_color(params, &w, *f, x);
		w.texpos += w.step;
		my_mlx_pixel_put(&params->img, x, f->drawstart++, w.color);
	}
}
