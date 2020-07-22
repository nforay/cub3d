/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:58:04 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 20:38:15 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		count_sprites(t_map *map)
{
	int i;
	int j;

	i = 0;
	map->n_sprite = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			if (char_in_str("2OPQRTUVXYZ", ft_toupper(map->tab[i][j])))
				map->n_sprite++;
			j++;
		}
		i++;
	}
}

int			build_sprite_tables(t_params *tmp, t_map *map)
{
	if (!(map->n_sprite))
		return (1);
	if (!(map->s_order = malloc(sizeof(int) * map->n_sprite)))
		return (parse_error("Sprite allocation error."));
	ft_memset(map->s_order, 0, sizeof(int) * map->n_sprite);
	if (!(map->s_dist = malloc(sizeof(double) * map->n_sprite)))
	{
		free(map->s_order);
		return (parse_error("Sprite allocation error."));
	}
	ft_memset(map->s_dist, 0, sizeof(double) * map->n_sprite);
	if (!(map->sprite = malloc(sizeof(t_sprite) * map->n_sprite)))
	{
		free(map->s_order);
		free(map->s_dist);
		return (parse_error("Sprite allocation error."));
	}
	ft_memset(map->sprite, 0, sizeof(t_sprite) * map->n_sprite);
	tmp->parser |= PARSER_SPR;
	return (1);
}

void		init_sprite(t_sprite *sprite, int i, int j, int tex)
{
	sprite->x = 0.5 + j;
	sprite->y = 0.5 + i;
	sprite->texture = tex;
	if (ft_toupper(tex) == 'O')
		sprite->health = 20;
	else
		sprite->health = 1;
}

static void	replace_sprite_square(t_map *map, int i, int j, char c)
{
	if (char_in_str("2opqrtuxyz", c))
		map->tab[i][j] = '0';
	else if (c == 'v' || c == 'V')
		map->tab[i][j] = 'V';
	else
		map->tab[i][j] = '9';
}

void		fill_sprite_table(t_map *map)
{
	int i;
	int j;
	int	k;

	i = 0;
	k = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			if (char_in_str("2OPQRTUVXYZ", ft_toupper(map->tab[i][j])))
			{
				init_sprite(&map->sprite[k], i, j, map->tab[i][j]);
				replace_sprite_square(map, i, j, map->tab[i][j]);
				k++;
			}
			j++;
		}
		i++;
	}
}
