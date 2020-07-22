/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:28:25 by nforay            #+#    #+#             */
/*   Updated: 2020/07/09 14:19:53 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_mlx_hooks(t_params *p)
{
	mlx_do_key_autorepeaton(p->vars.mlx);
	mlx_hook(p->vars.win, 2, 0x1, event_kbd_press, p);
	mlx_hook(p->vars.win, 3, 0x2, event_kbd_release, p);
	mlx_hook(p->vars.win, 33, (1L << 17), exit_hook, p);
	if (BONUS)
	{
		mlx_mouse_hide(p->vars.mlx, p->vars.win);
		mlx_hook(p->vars.win, 4, 0x4, event_mouse_press, p);
		mlx_hook(p->vars.win, 5, 0x8, event_mouse_release, p);
		mlx_hook(p->vars.win, 6, 0x40, event_mouse_move, p);
	}
}

int		exit_hook(t_params *params)
{
	quit(params);
	return (0);
}

int		event_kbd_press(int keycode, t_params *params)
{
	if (keycode == K_UP || keycode == K_Z)
		params->move |= M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move |= M_DOWN;
	else if (keycode == K_LEFT)
		params->move |= M_LEFT;
	else if (keycode == K_RIGHT)
		params->move |= M_RIGHT;
	else if (keycode == K_Q)
		params->move |= M_STRLE;
	else if (keycode == K_D)
		params->move |= M_STRRI;
	else if (keycode == K_ESC)
		quit(params);
	else if (BONUS)
		event_kbd_press_bonus(keycode, params);
	return (1);
}

int		event_kbd_release(int keycode, t_params *params)
{
	if (keycode == K_UP || keycode == K_Z)
		params->move &= ~M_UP;
	else if (keycode == K_DOWN || keycode == K_S)
		params->move &= ~M_DOWN;
	else if (keycode == K_LEFT)
		params->move &= ~M_LEFT;
	else if (keycode == K_RIGHT)
		params->move &= ~M_RIGHT;
	else if (keycode == K_Q)
		params->move &= ~M_STRLE;
	else if (keycode == K_D)
		params->move &= ~M_STRRI;
	else if (keycode == K_SHIFT)
		params->move &= ~M_SPRINT;
	else if (keycode == K_CTRL)
		params->move &= ~M_CTRL;
	return (1);
}
