/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:32:34 by nforay            #+#    #+#             */
/*   Updated: 2020/07/03 02:19:55 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_coord	getangle(t_coord a, t_coord b)
{
	t_coord	delta;
	double	angle;

	delta.x = b.x - a.x;
	delta.y = b.y - a.y;
	angle = atan2(delta.y, delta.x);
	delta.x = -cos(angle);
	delta.y = -sin(angle);
	return (delta);
}
