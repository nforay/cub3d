/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sprite_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:16:42 by nforay            #+#    #+#             */
/*   Updated: 2020/07/03 00:21:02 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		spr_delta(t_coord *delta, t_coord *pos, int x, int y)
{
	delta->x = pos->x - (int)pos->x + x;
	delta->y = pos->y - (int)pos->y + y;
	return (1);
}
