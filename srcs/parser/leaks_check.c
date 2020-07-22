/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:14:11 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 23:03:00 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	flood_fill(t_params *tmp, int x, int y)
{
	if (!(ft_strchr("NSEW", tmp->map.tmp[y][x])))
		tmp->map.tmp[y][x] = 'F';
	if (!(x) || !(y) || y == (tmp->map.size.y - 1) ||
		x == (tmp->map.size.x - 1))
	{
		ft_putendl_fd("Error\nMap is leaking.", 1);
		print_tab(tmp->map.tmp, tmp->map.size);
		free_tab(tmp->map.tmp, tmp->map.size.y);
		exit_free(tmp, 1);
	}
	if (y > 0 && reachable(tmp->map.tmp, y - 1, x))
		flood_fill(tmp, x, y - 1);
	if ((y < (tmp->map.size.y - 1)) && reachable(tmp->map.tmp, y + 1, x))
		flood_fill(tmp, x, y + 1);
	if ((x < (tmp->map.size.x - 1)) && reachable(tmp->map.tmp, y, x + 1))
		flood_fill(tmp, x + 1, y);
	if (x > 0 && reachable(tmp->map.tmp, y, x - 1))
		flood_fill(tmp, x - 1, y);
}
