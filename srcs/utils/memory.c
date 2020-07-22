/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:57:21 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 02:44:17 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	ft_dblswap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	free_tab(char **tab, int size)
{
	while (--size >= 0)
		free(tab[size]);
	free(tab);
}

void	free_allocated_tables(t_params *params)
{
	if (params->parser & PARSER_SPR)
	{
		free(params->map.s_order);
		free(params->map.s_dist);
		free(params->map.sprite);
	}
	if (params->parser & PARSER_BUF)
	{
		free(params->spritebuffer);
		free(params->zbuffer);
	}
	if (params->parser & PARSER_DOOR)
	{
		free(params->map.d_offset);
		free(params->map.d_state);
	}
}
