/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:14:28 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 02:34:48 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	player_strafe_left(t_params *params, double speed)
{
	double olddirx;
	double olddiry;

	olddirx = params->dir.x;
	olddiry = params->dir.y;
	params->dir.x = params->dir.y;
	params->dir.y = -olddirx;
	if (BONUS)
		params->pos = check_collision(params, speed);
	else
	{
		params->pos.x += params->dir.x * speed;
		params->pos.y += params->dir.y * speed;
	}
	params->dir.x = olddirx;
	params->dir.y = olddiry;
}

static void	player_strafe_right(t_params *params, double speed)
{
	double olddirx;
	double olddiry;

	olddirx = params->dir.x;
	olddiry = params->dir.y;
	params->dir.x = -params->dir.y;
	params->dir.y = olddirx;
	if (BONUS)
		params->pos = check_collision(params, speed);
	else
	{
		params->pos.x += params->dir.x * speed;
		params->pos.y += params->dir.y * speed;
	}
	params->dir.x = olddirx;
	params->dir.y = olddiry;
}

static void	player_move_forward(t_params *params, double speed)
{
	if (BONUS)
		params->pos = check_collision(params, speed);
	else
	{
		params->pos.x += params->dir.x * speed;
		params->pos.y += params->dir.y * speed;
	}
}

static void	player_move_backward(t_params *params, double speed)
{
	if (BONUS)
		params->pos = check_collision_back(params, speed * 0.5);
	else
	{
		params->pos.x -= params->dir.x * speed;
		params->pos.y -= params->dir.y * speed;
	}
}

void		move_player(t_params *params)
{
	double	speed;

	if (params->move & M_SPRINT)
		speed = params->movespeed * 1.5;
	else
		speed = params->movespeed;
	if (params->move & M_LEFT)
		player_rotate_left(params);
	if (params->move & M_RIGHT)
		player_rotate_right(params);
	if (params->move & M_STRLE && params->health > 0)
		player_strafe_left(params, speed * 0.7);
	if (params->move & M_STRRI && params->health > 0)
		player_strafe_right(params, speed * 0.7);
	if (params->move & M_UP && params->health > 0)
		player_move_forward(params, speed);
	if (params->move & M_DOWN && params->health > 0)
		player_move_backward(params, speed);
}
