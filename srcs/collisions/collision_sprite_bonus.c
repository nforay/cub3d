/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sprite_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:16:12 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 22:02:57 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord	spr_col_top_left(t_params *p, t_coord pos, t_coord orig, double radius)
{
	int		blocktop;
	int		blockleft;
	t_coord	delta;

	blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y);
	if (!blocktop && orig.y - (int)orig.y > (1 - radius))
		blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y + 1);
	blockleft = isblocking(p, (int)pos.x, (int)pos.y - 1);
	if (!blockleft && orig.x - (int)orig.x > (1 - radius))
		blockleft = isblocking(p, (int)pos.x + 1, (int)pos.y - 1);
	if (blocktop && (pos.x - (int)pos.x < radius))
		pos.x = (int)pos.x + radius;
	if (blockleft && (pos.y - (int)pos.y < radius))
		pos.y = (int)pos.y + radius;
	if (!(blocktop != 0 && blockleft != 0) && spr_delta(&delta, &pos, 0, 0) &&
			isblocking(p, (int)pos.x - 1, (int)pos.y - 1))
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + radius;
			else
				pos.y = (int)pos.y + radius;
		}
	return (pos);
}

t_coord	spr_col_top_right(t_params *p, t_coord pos, t_coord orig, double radius)
{
	int		blocktop;
	int		blockright;
	t_coord	delta;

	blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y);
	if (!blocktop && orig.y - (int)orig.y <= radius)
		blocktop = isblocking(p, (int)pos.x - 1, (int)pos.y - 1);
	blockright = isblocking(p, (int)pos.x, (int)pos.y + 1);
	if (!blockright && orig.x - (int)orig.x >= (1 - radius))
		blockright = isblocking(p, (int)pos.x + 1, (int)pos.y + 1);
	if (blocktop && (pos.x - (int)pos.x < radius))
		pos.x = (int)pos.x + radius;
	if (blockright && ((int)pos.y + 1 - pos.y < radius))
		pos.y = (int)pos.y + 1 - radius;
	if (!(blocktop != 0 && blockright != 0) && spr_delta(&delta, &pos, 0, 1) &&
		isblocking(p, (int)pos.x - 1, (int)pos.y + 1))
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + radius;
			else
				pos.y = (int)pos.y + 1 - radius;
		}
	return (pos);
}

t_coord	spr_col_bot_right(t_params *p, t_coord pos, t_coord orig, double radius)
{
	int		blockbot;
	int		blockright;
	t_coord	delta;

	blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y);
	if (!blockbot && orig.y - (int)orig.y < radius)
		blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y - 1);
	blockright = isblocking(p, (int)pos.x, (int)pos.y + 1);
	if (!blockright && orig.x - (int)orig.x < radius)
		blockright = isblocking(p, (int)pos.x - 1, (int)pos.y + 1);
	if (blockbot && ((int)pos.x + 1 - pos.x < radius))
		pos.x = (int)pos.x + 1 - radius;
	if (blockright && ((int)pos.y + 1 - pos.y < radius))
		pos.y = ((int)pos.y + 1) - radius;
	if (!(blockbot != 0 && blockright != 0) && spr_delta(&delta, &pos, 1, 1) &&
		isblocking(p, (int)pos.x + 1, (int)pos.y + 1))
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + 1 - radius;
			else
				pos.y = (int)pos.y + 1 - radius;
		}
	return (pos);
}

t_coord	spr_col_bot_left(t_params *p, t_coord pos, t_coord orig, double radius)
{
	int		blockbot;
	int		blockleft;
	t_coord	delta;

	blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y);
	if (!blockbot && orig.y - (int)orig.y > (1 - radius))
		blockbot = isblocking(p, (int)pos.x + 1, (int)pos.y + 1);
	blockleft = isblocking(p, (int)pos.x, (int)pos.y - 1);
	if (!blockleft && orig.x - (int)orig.x < radius)
		blockleft = isblocking(p, (int)pos.x - 1, (int)pos.y - 1);
	if (blockbot && ((int)pos.x + 1 - pos.x < radius))
		pos.x = (int)pos.x + 1 - radius;
	if (blockleft && (pos.y - (int)pos.y < radius))
		pos.y = (int)pos.y + radius;
	if (!(blockbot != 0 && blockleft != 0) && spr_delta(&delta, &pos, 1, 0) &&
		isblocking(p, (int)pos.x + 1, (int)pos.y - 1))
		if (delta.x * delta.x + delta.y * delta.y < radius * radius)
		{
			if (delta.x * delta.x > delta.y * delta.y)
				pos.x = (int)pos.x + 1 - radius;
			else
				pos.y = (int)pos.y + radius;
		}
	return (pos);
}

t_coord	spr_colision(t_params *params, t_coord orig, t_coord dir, double s)
{
	t_coord finalpos;
	t_coord dest;

	dest.x = orig.x + dir.x * s;
	dest.y = orig.y + dir.y * s;
	if (isblocking(params, (int)dest.x, (int)dest.y))
		return (orig);
	finalpos.x = dest.x;
	finalpos.y = dest.y;
	if (dir.x < 0)
	{
		if (dir.y < 0)
			finalpos = spr_col_top_left(params, finalpos, orig, 0.3);
		else
			finalpos = spr_col_top_right(params, finalpos, orig, 0.3);
	}
	else
	{
		if (dir.y < 0)
			finalpos = spr_col_bot_left(params, finalpos, orig, 0.3);
		else
			finalpos = spr_col_bot_right(params, finalpos, orig, 0.3);
	}
	return (finalpos);
}
