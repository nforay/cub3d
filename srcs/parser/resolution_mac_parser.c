/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution_mac_parser.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:32:12 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 23:47:10 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_intlen(int n, int len)
{
	if (n == -2147483648)
		return (10);
	if (n <= 0)
		n = -n;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_atoi_basic(const char *str)
{
	size_t	result;
	int		i;

	i = 0;
	result = 0;
	while ((str[i] == ' '))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	return (result);
}

int	parse_resolution(t_params *tmp, char *line)
{
	line += 2;
	if (!(tmp->w = ft_atoi_basic(line)))
		return (parse_error("Syntax: 'R \033[1;31mnumber\033[0;0m number'"));
	while (*line && *line == ' ')
		line++;
	line += get_intlen(tmp->w, 1);
	if (!(tmp->h = ft_atoi_basic(line)))
		return (parse_error("Syntax: 'R number \033[1;31mnumber\033[0;0m'"));
	tmp->parser |= PARSER_R;
	if (!(tmp->captureframe))
	{
		tmp->w = (tmp->w > 1920 ? 1920 : tmp->w);
		tmp->h = (tmp->h > 1080 ? 1080 : tmp->h);
	}
	return (1);
}
