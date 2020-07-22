/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:10:35 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 01:49:19 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		isblocking(t_params *params, int x, int y)
{
	if (x < 0 || x >= params->map.size.x || y < 0 || y >= params->map.size.y)
		return (1);
	if (params->map.tab[y][x] == '0' || (door_state(params, x, y) == 2 &&
			char_in_str("DGLM", ft_toupper(params->map.tab[y][x]))))
		return (0);
	if (params->map.tab[y][x] == '8' || params->map.tab[y][x] == '9')
		return (0);
	return (1);
}

t_coord	check_collision(t_params *params, double speed)
{
	t_coord	finalpos;
	t_coord	dest;

	dest.x = params->pos.x + params->dir.x * speed;
	dest.y = params->pos.y + params->dir.y * speed;
	if (isblocking(params, (int)dest.x, (int)dest.y))
		return (params->pos);
	finalpos.x = dest.x;
	finalpos.y = dest.y;
	if (params->dir.x < 0)
	{
		if (params->dir.y < 0)
			finalpos = collision_top_left(params, finalpos, 0.2);
		else
			finalpos = collision_top_right(params, finalpos, 0.2);
	}
	else
	{
		if (params->dir.y < 0)
			finalpos = collision_bot_left(params, finalpos, 0.2);
		else
			finalpos = collision_bot_right(params, finalpos, 0.2);
	}
	return (finalpos);
}

t_coord	check_collision_back(t_params *params, double speed)
{
	t_coord finalpos;
	t_coord dest;

	dest.x = params->pos.x - params->dir.x * speed;
	dest.y = params->pos.y - params->dir.y * speed;
	if (isblocking(params, (int)dest.x, (int)dest.y))
		return (params->pos);
	finalpos.x = dest.x;
	finalpos.y = dest.y;
	if (params->dir.x < 0)
	{
		if (params->dir.y < 0)
			finalpos = collision_bot_right(params, finalpos, 0.2);
		else
			finalpos = collision_bot_left(params, finalpos, 0.2);
	}
	else
	{
		if (params->dir.y < 0)
			finalpos = collision_top_right(params, finalpos, 0.2);
		else
			finalpos = collision_top_left(params, finalpos, 0.2);
	}
	return (finalpos);
}
