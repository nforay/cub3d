/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:05:17 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 02:07:05 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_bitmap	fill_header(t_params *params)
{
	t_bitmap	header;

	ft_memset(&header, 0, sizeof(header));
	header.filesize = (params->w * params->h * (params->img.bpp / 8)) + 54;
	header.pixeldataoffset = 54;
	header.headersize = 40;
	header.imagewidth = params->w;
	header.imageheight = params->h;
	header.planes = 1;
	header.bitsperpixel = params->img.bpp;
	header.imagesize = params->w * params->h * (params->img.bpp / 8);
	return (header);
}

static void		file_write(t_params *p, int fd, const void *buf, ssize_t len)
{
	if (write(fd, buf, len) != len)
	{
		perror("Error\nfile_write");
		quit(p);
	}
}

int				save_screenshot(t_params *params)
{
	int				fd;
	t_bitmap		bmp;
	int				i;
	unsigned int	*line;

	params->img.addr = mlx_get_data_addr(params->img.img,
		&(params->img.bpp), &(params->img.line_length), &(params->img.endian));
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	bmp = fill_header(params);
	if (fd < 0)
		return (1);
	file_write(params, fd, "BM", 2);
	file_write(params, fd, &bmp, sizeof(bmp));
	i = 0;
	while (i < params->h)
	{
		line = (unsigned int *)&params->img.addr[(params->h - i - 1) *
			params->img.line_length];
		file_write(params, fd, line, params->img.line_length);
		i++;
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
