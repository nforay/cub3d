/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:23:40 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 20:46:22 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		fix_map(char **a, t_icoord size, int i, int j)
{
	char	*tmp;

	while (i < size.y)
	{
		if ((int)ft_strlen(a[i]) != size.x)
		{
			if (!(tmp = malloc(sizeof(char *) * (size.x + 1))))
				return (parse_error("Map allocation error."));
			ft_memset(tmp, '0', size.x);
			ft_memcpy(tmp, a[i], ft_strlen(a[i]));
			free(a[i]);
			a[i] = tmp;
		}
		j = 0;
		while (j < size.x)
		{
			if (a[i][j] == ' ')
				a[i][j] = '0';
			j++;
		}
		i++;
	}
	return (1);
}

int		duplicate_map(t_map *map, t_icoord size)
{
	int	i;

	map->tmp = map->tab;
	if (!(map->tab = malloc(sizeof(char *) * size.y)))
		return (parse_error("Map allocation error."));
	i = 0;
	while (i < size.y)
	{
		if (!(map->tab[i] = malloc(sizeof(char *) * (size.x + 1))))
		{
			while (--i >= 0)
				free(map->tab[i]);
			return (parse_error("Map allocation error."));
		}
		ft_memcpy(map->tab[i], map->tmp[i], size.x + 1);
		i++;
	}
	return (1);
}

char	**ft_tab_join(char **tab, const char *str, int size)
{
	char	**ptr;
	int		i;

	if (!str)
		return (tab);
	if (!(ptr = malloc(sizeof(char *) * (size + 1))))
		return (tab);
	i = 0;
	while (i < size)
	{
		ptr[i] = tab[i];
		i++;
	}
	if (!(ptr[i] = ft_strdup(str)))
	{
		free(ptr);
		return (tab);
	}
	free(tab);
	return (ptr);
}

int		validate_map_line(t_map *map, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if ((char_in_str("NSEW", line[i]) ||
			(BONUS && char_in_str("nsew", line[i]))) && j == 0 &&
			map->start.x == 0 && map->start.y == 0)
		{
			map->start.x = i;
			map->start.y = map->size.y;
			j++;
		}
		else if (char_in_str("NSEWnsew", line[i]))
			return (parse_error("More than one start point."));
		else if (BONUS && !char_in_str(STRBONUS, ft_toupper(line[i])))
			return (parse_error("Unknown character, expected map."));
		else if (!BONUS && !char_in_str(" 012", ft_toupper(line[i])))
			return (parse_error("Unknown character, expected map."));
		i++;
	}
	return (1);
}

int		parse_map(t_params *tmp, char *line)
{
	t_map	*this;

	this = &tmp->map;
	if (!(validate_map_line(this, line)))
		return (0);
	if (tmp->parser == 255)
		if (!(this->tab = malloc(sizeof(char *) * 1)))
			return (parse_error("Map allocation error."));
	if (!(this->tab = ft_tab_join((char **)this->tab, line, this->size.y)))
		return (parse_error("Map Join allocation error."));
	tmp->parser |= PARSER_MAP;
	this->size.y++;
	if ((int)ft_strlen(line) > this->size.x)
		this->size.x = ft_strlen(line);
	return (1);
}
