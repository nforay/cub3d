/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_success.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:42:20 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 20:37:18 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	make_buffers(t_params *tmp)
{
	if (!(tmp->spritebuffer = malloc(tmp->w * tmp->h)))
		exit_msg(tmp, "Buffer allocation error.");
	ft_memset(tmp->spritebuffer, 0, (tmp->w * tmp->h));
	if (!(tmp->zbuffer = malloc(sizeof(double) * tmp->w)))
	{
		free(tmp->spritebuffer);
		exit_msg(tmp, "Buffer allocation error.");
	}
	ft_memset(tmp->zbuffer, 0, sizeof(double) * tmp->w);
	tmp->parser |= PARSER_BUF;
}

void	make_doors_table(t_params *tmp, t_map *map)
{
	if (!(map->d_state = malloc(map->size.y * map->size.x)))
		exit_msg(tmp, "Doors allocation error.");
	ft_memset(map->d_state, 0, map->size.y * map->size.x);
	if (!(map->d_offset = malloc(sizeof(double) * map->size.x * map->size.y)))
	{
		free(map->d_state);
		exit_msg(tmp, "Doors allocation error.");
	}
	ft_memset(map->d_offset, 0, sizeof(double) * map->size.y * map->size.x);
	tmp->parser |= PARSER_DOOR;
}

void	init_game(t_params *params)
{
	params->mapwidth = &params->map.size.x;
	params->mapheight = &params->map.size.y;
	params->baseshadecol.r = 1.0;
	params->baseshadecol.g = 1.0;
	params->baseshadecol.b = 1.0;
	if (!(params->shadedist))
		params->shadedist = 4;
	params->shadefiring = 2;
	params->shadecol = params->baseshadecol;
	params->mouse.x = (int)(params->w / 2);
	params->mouse.y = (int)(params->h / 2);
	if (!(params->cosr) && !(params->sinr))
	{
		params->cosr = (BONUS ? cos(0.005) : cos(0.02));
		params->cosmr = (BONUS ? cos(-0.005) : cos(-0.02));
		params->sinr = (BONUS ? sin(0.005) : sin(0.02));
		params->sinmr = (BONUS ? sin(-0.005) : sin(-0.02));
	}
	params->alternate = 0;
	params->interlace = 0;
	params->debug = 1;
}

void	initmap(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < params->map.size.y)
	{
		while (j < params->map.size.x)
		{
			if (char_in_str("GLM", ft_toupper(params->map.tab[i][j])) ||
				ft_toupper(params->map.tab[i][j]) == 'D')
			{
				set_door_state(params, j, i, 0);
				set_door_offset(&params->map, j, i, 0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	prepare_map(t_params *tmp)
{
	if (!(tmp->map.start.x) && !(tmp->map.start.y))
		exit_msg(tmp, "No player start point.");
	if (!(fix_map(tmp->map.tab, tmp->map.size, 0, 0)))
		exit_free(tmp, 1);
	duplicate_map(&tmp->map, tmp->map.size);
	flood_fill(tmp, tmp->map.start.x, tmp->map.start.y);
	if (BONUS)
		optimize_tab(&tmp->map, tmp->map.size);
	else
		free_tab(tmp->map.tmp, tmp->map.size.y);
	count_sprites(&tmp->map);
	if (!(build_sprite_tables(tmp, &tmp->map)))
		exit_free(tmp, 1);
	fill_sprite_table(&tmp->map);
	make_buffers(tmp);
	make_doors_table(tmp, &tmp->map);
	init_game(tmp);
	init_player(tmp);
	initmap(tmp);
}
