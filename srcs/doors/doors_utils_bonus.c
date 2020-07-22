/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:08:33 by nforay            #+#    #+#             */
/*   Updated: 2020/07/10 16:35:36 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_door_offset(t_map *map, int x, int y, double offset)
{
	double	*adr;

	adr = map->d_offset + ((y * map->size.x + x));
	*(double *)adr = offset;
}

void	add_door_offset(t_map *map, int x, int y, double offset)
{
	double	*adr;

	adr = map->d_offset + ((y * map->size.x + x));
	*(double *)adr += offset;
}

double	door_offset(t_map *map, int x, int y)
{
	if (x >= 0 && x < map->size.x && y >= 0 && y < map->size.y)
		return (*(double *)(map->d_offset + (x + y * map->size.x)));
	else
		return ((double)0);
}

void	set_door_state(t_params *params, int x, int y, int state)
{
	char	*adr;

	adr = params->map.d_state + ((y * params->map.size.x + x));
	*(char*)adr = state;
}

int		door_state(t_params *params, int x, int y)
{
	if (x >= 0 && x < params->map.size.x && y >= 0 && y < params->map.size.y)
		return (*(char*)(params->map.d_state + (x + y * params->map.size.x)));
	else
		return (0);
}
