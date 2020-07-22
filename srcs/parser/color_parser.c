/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:29:33 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 23:01:20 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_string_to_int(char **str)
{
	int	result;

	result = 0;
	if (**str == ',')
		*str += 1;
	if (!(ft_isdigit(**str)))
		return (-1);
	while (ft_isdigit(**str))
	{
		result *= 10;
		result += **str - 48;
		*str += 1;
	}
	return (result > 255 ? -1 : result);
}

int	parse_color(t_params *tmp, char *line)
{
	t_color	*color;

	if (!ft_strncmp(line, "F ", 2) && (tmp->parser |= PARSER_F))
		color = &tmp->floor;
	else
	{
		tmp->parser |= PARSER_C;
		color = &tmp->ceil;
	}
	line += 2;
	while (*line && *line == ' ')
		line++;
	if ((color->r = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '\033[1;31m0-255\033[0;0m 0-225 0-255'"));
	if ((color->g = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '0-255 \033[1;31m0-255\033[0;0m 0-255'"));
	if ((color->b = rgb_string_to_int(&line)) < 0)
		return (parse_error("Syntax: '0-255 0-255 \033[1;31m0-255\033[0;0m'"));
	return (1);
}
