/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:33:09 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 02:35:07 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		event_kbd_press_editor_next(int keycode, t_params *params)
{
	if (keycode == K_NUM5)
		if (ft_get_bloc_id(params) == 'G')
			ft_set_bloc_id(params, 'L');
		else if (ft_get_bloc_id(params) == 'L')
			ft_set_bloc_id(params, 'M');
		else
			ft_set_bloc_id(params, 'G');
	else if (keycode == K_NUM6)
		ft_set_bloc_id(params, 'A');
	else if (keycode == K_NUM7)
		if (ft_get_bloc_id(params) == 'B')
			ft_set_bloc_id(params, 'C');
		else
			ft_set_bloc_id(params, 'B');
	else if (keycode == K_NUM8)
	{
		if (ft_get_bloc_id(params) > 'G' && ft_get_bloc_id(params) < 'K')
			ft_set_bloc_id(params, ft_get_bloc_id(params) + 1);
		else
			ft_set_bloc_id(params, 'H');
	}
}

void		event_kbd_press_editor(int keycode, t_params *params)
{
	if (keycode == K_NUM1)
		if (ft_get_bloc_id(params) == '0')
			ft_set_bloc_id(params, '1');
		else
			ft_set_bloc_id(params, '0');
	else if (keycode == K_NUM2)
		if (ft_get_bloc_id(params) == '9')
			ft_set_bloc_id(params, '8');
		else
			ft_set_bloc_id(params, '9');
	else if (keycode == K_NUM3)
		if (ft_get_bloc_id(params) > '2' && ft_get_bloc_id(params) < '6')
			ft_set_bloc_id(params, ft_get_bloc_id(params) + 1);
		else
			ft_set_bloc_id(params, '3');
	else if (keycode == K_NUM4)
		ft_set_bloc_id(params, 'D');
	else
		event_kbd_press_editor_next(keycode, params);
}

static void	player_interact(t_params *params)
{
	t_icoord	target;
	char		c;

	target.x = (int)(params->pos.x + params->dir.x);
	target.y = (int)(params->pos.y + params->dir.y);
	c = ft_toupper(params->map.tab[target.y][target.x]);
	if ((c == 'L' && !(params->equiped & INV_KEY_Y)) || (c == 'M' &&
			!(params->equiped & INV_KEY_R)))
		return ;
	if (!(door_state(params, target.x, target.y)))
		set_door_state(params, target.x, target.y, 1);
	else if (door_state(params, target.x, target.y) == 3)
		set_door_state(params, target.x, target.y, 1);
	else if (door_state(params, target.x, target.y) == 1)
		set_door_state(params, target.x, target.y, 3);
	else if (door_state(params, target.x, target.y) == 2)
		set_door_state(params, target.x, target.y, 3);
}

void		event_kbd_press_bonus(int keycode, t_params *params)
{
	if (keycode == K_SHIFT)
		params->move |= M_SPRINT;
	else if (keycode == K_CTRL)
		params->move |= M_CTRL;
	else if (keycode == K_E)
		player_interact(params);
	else if (keycode == K_1)
		params->shadedist -= 0.1;
	else if (keycode == K_2)
		params->shadedist += 0.1;
	else if (keycode == K_3)
		params->debug = !params->debug;
	else if (keycode == K_4)
	{
		params->interlace = !params->interlace;
		params->alternate = 0;
	}
	else if (keycode == K_5)
		print_tab(params->map.tab, params->map.size);
	else
		event_kbd_press_editor(keycode, params);
}
