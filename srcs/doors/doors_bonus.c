/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:13:47 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 22:09:51 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	movedoor(int i, int j, t_params *params)
{
	if (door_state(params, i, j) == 1 || door_state(params, i, j) == 2)
	{
		add_door_offset(&params->map, i, j, params->movespeed / 4);
		if (door_offset(&params->map, i, j) > 3 &&
			!(i == (int)params->pos.x && j == (int)params->pos.y))
		{
			set_door_offset(&params->map, i, j, 1);
			set_door_state(params, i, j, 3);
		}
		else if (door_offset(&params->map, i, j) > 1)
			set_door_state(params, i, j, 2);
	}
	else if (door_state(params, i, j) == 3)
	{
		add_door_offset(&params->map, i, j, -(params->movespeed / 4));
		if (door_offset(&params->map, i, j) <= 0)
		{
			set_door_offset(&params->map, i, j, 0);
			set_door_state(params, i, j, 0);
		}
	}
}

void	pushwall(int i, int j, t_params *params)
{
	if (door_state(params, i, j) == 1)
	{
		add_door_offset(&params->map, i, j, params->movespeed / 4);
		if (door_offset(&params->map, i, j) >= 2)
			set_door_state(params, i, j, 2);
	}
}

void	refreshmap(t_params *params)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < params->map.size.y)
	{
		while (x < params->map.size.x)
		{
			if (char_in_str("GLM", ft_toupper(params->map.tab[y][x])))
				movedoor(x, y, params);
			else if (ft_toupper(params->map.tab[y][x]) == 'D')
				pushwall(x, y, params);
			x++;
		}
		x = 0;
		y++;
	}
}
