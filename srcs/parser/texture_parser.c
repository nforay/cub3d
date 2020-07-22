/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:30:23 by nforay            #+#    #+#             */
/*   Updated: 2020/07/09 15:12:13 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	convert_endian(t_image *img)
{
	int		i;
	int		color;
	char	*dst;

	i = 0;
	while (i < (img->width * img->height))
	{
		color = *(int*)(img->addr + i * (img->bpp / 8));
		color = ((color >> 24) & 0xff) | ((color << 8) & 0xff0000) |
				((color >> 8) & 0xff00) | ((color << 24) & 0xff000000);
		dst = img->addr + (i * (img->bpp / 8));
		*(unsigned int*)dst = color;
		i++;
	}
}

int			load_xpm(char *path, t_image *img, t_params *params)
{
	int		local_endian;

	if (!(img->img = mlx_xpm_file_to_image(params->vars.mlx,
			path, &(img->width), &(img->height))))
		return (0);
	if (!(img->addr = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->line_length), &(img->endian))))
		return (0);
	local_endian = 0x11223344;
	if (((unsigned char *)&local_endian)[0] == 0x11)
		local_endian = 1;
	else
		local_endian = 0;
	if (local_endian != img->endian)
		convert_endian(img);
	return (1);
}

int			load_texture(t_params *tmp, t_image *img, char *path, int parser)
{
	int fd;

	while (*path && *path == ' ')
		path++;
	if (*path == 0)
		return (0);
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Error", 1);
		perror(path);
		return (0);
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd("Error", 1);
		perror(path);
		return (0);
	}
	if (!(load_xpm(path, img, tmp)))
		exit_msg(tmp, "Mlx failed to load texture.");
	if (parser != 0)
		tmp->parser |= parser;
	return (1);
}

int			parse_texture(t_params *tmp, char *line)
{
	if (!ft_strncmp(line, "S ", 2) && !(tmp->parser & PARSER_S))
		return (load_texture(tmp, &tmp->sprite, line + 2, PARSER_S));
	else if (!ft_strncmp(line, "NO ", 3) && !(tmp->parser & PARSER_NO))
		return (load_texture(tmp, &tmp->north, line + 3, PARSER_NO));
	else if (!ft_strncmp(line, "SO ", 3) && !(tmp->parser & PARSER_SO))
		return (load_texture(tmp, &tmp->south, line + 3, PARSER_SO));
	else if (!ft_strncmp(line, "EA ", 3) && !(tmp->parser & PARSER_EA))
		return (load_texture(tmp, &tmp->east, line + 3, PARSER_EA));
	else if (!ft_strncmp(line, "WE ", 3) && !(tmp->parser & PARSER_WE))
		return (load_texture(tmp, &tmp->west, line + 3, PARSER_WE));
	else if (BONUS && !ft_strncmp(line, "FT ", 3))
		return (load_texture(tmp, &tmp->infloortex, line + 3, PARSER_F));
	else if (BONUS && !ft_strncmp(line, "SK ", 3))
		return (load_texture(tmp, &tmp->skybox, line + 3, PARSER_C));
	return (parse_error_detail(tmp, line));
}
