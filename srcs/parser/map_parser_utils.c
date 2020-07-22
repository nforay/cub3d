/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:26:53 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 23:09:50 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		reachable(char **tab, int y, int x)
{
	if (char_in_str("0289ABCDGHIJKLMOPQRTUVXYZ", ft_toupper(tab[y][x])))
		return (1);
	return (0);
}

int		check_surroundings(char **a, t_icoord s, t_icoord p)
{
	if (p.y > 0 && p.x > 0 && char_in_str("NSEWFnsew", a[p.y - 1][p.x - 1]))
		return (0);
	else if (p.y > 0 && char_in_str("NSEWFnsew", a[p.y - 1][p.x]))
		return (0);
	else if (p.y > 0 && p.x < (s.x - 2) &&
			char_in_str("NSEWFnsew", a[p.y - 1][p.x + 1]))
		return (0);
	else if (p.x < (s.x - 2) && char_in_str("NSEWFnsew", a[p.y][p.x + 1]))
		return (0);
	else if (p.y < (s.y - 2) && p.x < (s.x - 2) &&
			char_in_str("NSEWFnsew", a[p.y + 1][p.x + 1]))
		return (0);
	else if (p.y < (s.y - 2) && char_in_str("NSEWFnsew", a[p.y + 1][p.x]))
		return (0);
	else if (p.y < (s.y - 2) && p.x > 0 &&
			char_in_str("NSEWFnsew", a[p.y + 1][p.x - 1]))
		return (0);
	else if (p.x > 0 && char_in_str("NSEWFnsew", a[p.y][p.x - 1]))
		return (0);
	return (1);
}

void	optimize_tab(t_map *map, t_icoord size)
{
	int			i;
	int			j;
	t_icoord	point;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			point.y = i;
			point.x = j;
			if (!(char_in_str("NSEW0nsew", map->tmp[i][j])) &&
					check_surroundings(map->tmp, size, point))
				map->tab[i][j] = '0';
			j++;
		}
		i++;
	}
	free_tab(map->tmp, size.y);
}
