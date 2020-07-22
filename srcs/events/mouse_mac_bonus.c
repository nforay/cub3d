/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mac_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:25:30 by nforay            #+#    #+#             */
/*   Updated: 2020/07/19 23:48:30 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		event_mouse_press(int button, int x, int y, t_params *params)
{
	(void)x;
	(void)y;
	if (button == 1 && params->health > 0 && params->equiped & INV_GUN &&
		params->weaponcd == 0 && params->ammo > 0)
	{
		params->firing = 1;
		params->weaponcd = params->weaponbasecd;
		params->ammo--;
	}
	return (0);
}

int		event_mouse_release(int button, int x, int y, t_params *params)
{
	(void)x;
	(void)y;
	if (button == 1)
		params->firing = 0;
	return (0);
}

void	mouse_move_right(t_params *params, int diff, int x, int y)
{
	params->mouse.x = x;
	while (diff-- != 0)
		player_rotate_right(params);
	if (x > (int)(params->w * 0.7))
	{
		mlx_mouse_move(params->vars.win, (int)(params->w / 2), y);
		params->mouse.x = (int)(params->w / 2);
	}
}

void	mouse_move_left(t_params *params, int diff, int x, int y)
{
	params->mouse.x = x;
	while (diff-- != 0)
		player_rotate_left(params);
	if (x < (int)(params->w * 0.3))
	{
		mlx_mouse_move(params->vars.win, (int)(params->w / 2), y);
		params->mouse.x = (int)(params->w / 2);
	}
}

int		event_mouse_move(int x, int y, t_params *params)
{
	int	diff;

	diff = abs(params->mouse.x - x);
	diff = (diff > 6 ? 6 : diff);
	if (y < (int)(params->h * 0.3) || y > (int)(params->h * 0.7))
		mlx_mouse_move(params->vars.win, x, (int)(params->h / 2));
	if (x > params->mouse.x)
		mouse_move_right(params, diff, x, y);
	else if (x < params->mouse.x)
		mouse_move_left(params, diff, x, y);
	return (0);
}
