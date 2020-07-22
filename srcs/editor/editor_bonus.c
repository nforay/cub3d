/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:27:16 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 22:23:30 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_get_bloc_id(t_params *params)
{
	int	x;
	int	y;

	x = (int)(params->pos.x + params->dir.x);
	y = (int)(params->pos.y + params->dir.y);
	if (x >= 0 && y >= 0 && x < params->map.size.x && y < params->map.size.y &&
		!(x == (int)params->pos.x && y == (int)params->pos.y))
		return (ft_toupper(params->map.tab[y][x]));
	return (0);
}

void	ft_set_bloc_id(t_params *params, int id)
{
	int	x;
	int	y;
	int	type;

	type = 0;
	if (id >= 'A' && params->move & M_CTRL)
		type = 32;
	x = (int)(params->pos.x + params->dir.x);
	y = (int)(params->pos.y + params->dir.y);
	if (x >= 0 && y >= 0 && x < params->map.size.x && y < params->map.size.y &&
		!(x == (int)params->pos.x && y == (int)params->pos.y))
		params->map.tab[y][x] = id + type;
}
