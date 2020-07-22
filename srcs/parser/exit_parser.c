/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:36:08 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 16:16:43 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_images(t_params *tmp)
{
	if (tmp->parser & PARSER_NO)
		mlx_destroy_image(tmp->vars.mlx, tmp->north.img);
	if (tmp->parser & PARSER_SO)
		mlx_destroy_image(tmp->vars.mlx, tmp->south.img);
	if (tmp->parser & PARSER_EA)
		mlx_destroy_image(tmp->vars.mlx, tmp->east.img);
	if (tmp->parser & PARSER_WE)
		mlx_destroy_image(tmp->vars.mlx, tmp->west.img);
	if (tmp->parser & PARSER_S)
		mlx_destroy_image(tmp->vars.mlx, tmp->sprite.img);
}

void	exit_free(t_params *tmp, int quit)
{
	destroy_images(tmp);
	if (tmp->parser & PARSER_MAP)
		free_tab(tmp->map.tab, tmp->map.size.y);
	if (tmp->parser & PARSER_SPR)
	{
		free(tmp->map.s_order);
		free(tmp->map.s_dist);
		free(tmp->map.sprite);
	}
	if (tmp->parser & PARSER_BUF)
	{
		free(tmp->spritebuffer);
		free(tmp->zbuffer);
	}
	if (tmp->parser & PARSER_DOOR)
	{
		free(tmp->map.d_offset);
		free(tmp->map.d_state);
	}
	if (BONUS)
		destroy_bonus_images(tmp);
	free(tmp->vars.mlx);
	if (quit)
		exit(EXIT_FAILURE);
}

void	exit_msg(t_params *tmp, char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit_free(tmp, 1);
}
