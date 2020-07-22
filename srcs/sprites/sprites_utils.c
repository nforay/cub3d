/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:21:21 by nforay            #+#    #+#             */
/*   Updated: 2020/07/03 13:46:28 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_writebuffer(t_params *params, int x, int y)
{
	char	*adr;

	adr = params->spritebuffer + ((y * params->w + x));
	*(char*)adr = 1;
}

int		ft_bufferstate(t_params *params, int x, int y)
{
	if (x >= 0 && x < params->w && y >= 0 && y < params->h)
		return (*(char*)(params->spritebuffer + ((x + y * params->w))));
	else
		return (1);
}

void	sortsprites(int *order, double *distance, int number)
{
	int i;
	int	j;

	i = 0;
	j = 1;
	while (i < number)
	{
		while (j < number)
		{
			if (distance[j] < distance[i])
			{
				ft_swap(&order[i], &order[j]);
				ft_dblswap(&distance[i], &distance[j]);
			}
			j++;
		}
		i++;
		j = i;
	}
}

void	get_sprite_dist(t_params *p)
{
	int		i;
	t_coord	delta;

	i = 0;
	while (i < p->map.n_sprite)
	{
		delta.x = p->pos.x - p->map.sprite[i].x;
		delta.y = p->pos.y - p->map.sprite[i].y;
		p->map.s_order[i] = i;
		p->map.s_dist[i] = sqrt(delta.x * delta.x + delta.y * delta.y);
		i++;
	}
}

void	newframe_init_sprite(t_params *params)
{
	get_sprite_dist(params);
	sortsprites(params->map.s_order, params->map.s_dist, params->map.n_sprite);
	get_sprite_pos(params);
	ft_memset(params->spritebuffer, 0, sizeof(char) * params->w * params->h);
}
