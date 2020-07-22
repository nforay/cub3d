/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:18:07 by nforay            #+#    #+#             */
/*   Updated: 2020/07/02 22:40:13 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_rotate_left(t_params *params)
{
	double	olddirx;
	double	oldplanex;

	olddirx = params->dir.x;
	params->dir.x = (params->dir.x * params->cosmr) -
		(params->dir.y * params->sinmr);
	params->dir.y = (olddirx * params->sinmr) + (params->dir.y * params->cosmr);
	oldplanex = params->plane.x;
	params->plane.x = (params->plane.x * params->cosmr) -
		(params->plane.y * params->sinmr);
	params->plane.y = (oldplanex * params->sinmr) +
		(params->plane.y * params->cosmr);
}

void	player_rotate_right(t_params *params)
{
	double	olddirx;
	double	oldplanex;

	olddirx = params->dir.x;
	params->dir.x = (params->dir.x * params->cosr) -
		(params->dir.y * params->sinr);
	params->dir.y = (olddirx * params->sinr) + (params->dir.y * params->cosr);
	oldplanex = params->plane.x;
	params->plane.x = (params->plane.x * params->cosr) -
		(params->plane.y * params->sinr);
	params->plane.y = (oldplanex * params->sinr) +
		(params->plane.y * params->cosr);
}
