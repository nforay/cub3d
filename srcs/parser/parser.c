/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:24:14 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 20:50:47 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		open_fd(t_params *tmp, char *path)
{
	int	fd;

	fd = 0;
	if (ft_strlen(path) < 4 || !(ft_strrchr(path, '.')))
		exit_msg(tmp, "Not a cub file.");
	if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4) == 0)
		fd = open(path, O_RDONLY);
	else
		exit_msg(tmp, "Not a cub file.");
	if (fd == -1)
	{
		perror("Error\nopen_fd");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		parse_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	return (0);
}

int		parse_error_detail(t_params *tmp, char *line)
{
	if (!ft_strncmp(line, "R ", 2) && (tmp->parser & PARSER_R))
		return (parse_error("Element R already present"));
	else if (!ft_strncmp(line, "NO ", 3) && (tmp->parser & PARSER_NO))
		return (parse_error("Element NO already present"));
	else if (!ft_strncmp(line, "SO ", 3) && (tmp->parser & PARSER_SO))
		return (parse_error("Element SO already present"));
	else if (!ft_strncmp(line, "WE ", 3) && (tmp->parser & PARSER_WE))
		return (parse_error("Element WE already present"));
	else if (!ft_strncmp(line, "EA ", 3) && (tmp->parser & PARSER_EA))
		return (parse_error("Element EA already present"));
	else if (!ft_strncmp(line, "S ", 2) && (tmp->parser & PARSER_S))
		return (parse_error("Element S already present"));
	else if (!ft_strncmp(line, "F ", 2) && (tmp->parser & PARSER_F))
		return (parse_error("Element F already present"));
	else if (!ft_strncmp(line, "C ", 2) && (tmp->parser & PARSER_C))
		return (parse_error("Element C already present"));
	return (parse_error("Element missing or unknown."));
}

int		parse_line(t_params *tmp, char *line)
{
	if (!ft_strncmp(line, "R ", 2) && !(tmp->parser & PARSER_R))
		return (parse_resolution(tmp, line));
	else if (!ft_strncmp(line, "S ", 2) || !ft_strncmp(line, "NO ", 3) ||
			!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "EA ", 3) ||
			!ft_strncmp(line, "WE ", 3))
		return (parse_texture(tmp, line));
	if ((!ft_strncmp(line, "F ", 2) && !(tmp->parser & PARSER_F)) ||
			(!ft_strncmp(line, "C ", 2) && !(tmp->parser & PARSER_C)))
		return (parse_color(tmp, line));
	if ((tmp->parser & PARSER_MAP) && (*line == 0))
		return (parse_error("Empty line during map parsing."));
	else if (*line == 0 && !(tmp->parser & PARSER_MAP))
		return (1);
	else if ((tmp->parser == 255) || (tmp->parser & PARSER_MAP))
		return (parse_map(tmp, line));
	else if (BONUS && !(tmp->parser & PARSER_MAP))
		return (parse_bonus(tmp, line));
	return (parse_error_detail(tmp, line));
}

void	parse_fd(t_params *tmp, int fd)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(parse_line(tmp, line)))
		{
			free(line);
			while (get_next_line(fd, &line) > 0)
				free(line);
			free(line);
			exit_free(tmp, 1);
		}
		free(line);
	}
	if (ret == -1)
		exit_free(tmp, 1);
	if (*line != 0)
		parse_line(tmp, line);
	free(line);
	if (close(fd) == -1)
	{
		perror("Error\nparse_fd");
		exit_free(tmp, 1);
	}
}
