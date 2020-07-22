/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:11:22 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 22:06:17 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord	collision_top_left(t_params *p, t_coord pos, double radius)
{
	int		blocktop;
	int		blockleft;
	t_coord	delta;

	blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y);
	blockleft = isblocking(p, (int)pos.x, (int)pos.y - 1);
	if (blocktop && (pos.x - (int)pos.x < radius))
		pos.x = (int)pos.x + radius;
	if (blockleft && (pos.y - (int)pos.y < radius))
		pos.y = (int)pos.y + radius;
	if (!(blocktop != 0 && blockleft != 0) &&
			isblocking(p, (int)pos.x - 1, (int)pos.y - 1))
	{
		delta.x = pos.x - (int)pos.x;
		delta.y = pos.y - (int)pos.y;
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + radius;
			else
				pos.y = (int)pos.y + radius;
		}
	}
	return (pos);
}

t_coord	collision_top_right(t_params *p, t_coord pos, double radius)
{
	int		blocktop;
	int		blockright;
	t_coord	delta;

	blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y);
	blockright = isblocking(p, (int)pos.x, (int)pos.y + 1);
	if (blocktop && (pos.x - (int)pos.x < radius))
		pos.x = (int)pos.x + radius;
	if (blockright && ((int)pos.y + 1 - pos.y < radius))
		pos.y = (int)pos.y + 1 - radius;
	if (!(blocktop != 0 && blockright != 0) &&
		isblocking(p, (int)pos.x - 1, (int)pos.y + 1))
	{
		delta.x = pos.x - (int)pos.x;
		delta.y = pos.y - ((int)pos.y + 1);
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + radius;
			else
				pos.y = (int)pos.y + 1 - radius;
		}
	}
	return (pos);
}

t_coord	collision_bot_right(t_params *p, t_coord pos, double radius)
{
	int		blockbot;
	int		blockright;
	t_coord	delta;

	blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y);
	blockright = isblocking(p, (int)pos.x, (int)pos.y + 1);
	if (blockbot && ((int)pos.x + 1 - pos.x < radius))
		pos.x = (int)pos.x + 1 - radius;
	if (blockright && ((int)pos.y + 1 - pos.y < radius))
		pos.y = ((int)pos.y + 1) - radius;
	if (!(blockbot != 0 && blockright != 0) &&
			isblocking(p, (int)pos.x + 1, (int)pos.y + 1))
	{
		delta.x = pos.x - ((int)pos.x + 1);
		delta.y = pos.y - ((int)pos.y + 1);
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + 1 - radius;
			else
				pos.y = (int)pos.y + 1 - radius;
		}
	}
	return (pos);
}

t_coord	collision_bot_left(t_params *p, t_coord pos, double radius)
{
	int		blockbot;
	int		blockleft;
	t_coord	delta;

	blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y);
	blockleft = isblocking(p, (int)pos.x, (int)pos.y - 1);
	if (blockbot && ((int)pos.x + 1 - pos.x < radius))
		pos.x = (int)pos.x + 1 - radius;
	if (blockleft && (pos.y - (int)pos.y < radius))
		pos.y = (int)pos.y + radius;
	if (!(blockbot != 0 && blockleft != 0) &&
		isblocking(p, (int)pos.x + 1, (int)pos.y - 1))
	{
		delta.x = pos.x - ((int)pos.x + 1);
		delta.y = pos.y - (int)pos.y;
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + 1 - radius;
			else
				pos.y = (int)pos.y + radius;
		}
	}
	return (pos);
}
