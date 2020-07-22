/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_update_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:33:04 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 16:50:43 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_sprite_health(t_params *params, t_sprite *this)
{
	if (this->hit == 0)
		return ;
	else if (this->hit == 2)
	{
		this->health -= 5;
		if (this->health > 0)
			this->hit = 1;
	}
	if (params->weaponcd <= 1)
		this->hit = 0;
}

static void	sprite_attack_player(t_params *params)
{
	if (params->health > 0)
	{
		params->health -= 1;
		params->shadecol.r = 3;
	}
	else
		params->health = 0;
}

static void	sprite_interact(t_params *p, t_coord orig, t_coord dir)
{
	t_icoord	target;
	char		c;

	target.x = (int)(orig.x + dir.x);
	target.y = (int)(orig.y + dir.y);
	c = ft_toupper(p->map.tab[target.y][target.x]);
	if (!char_in_str("GLM", c))
	{
		target.x = orig.x;
		target.y = orig.y;
		c = ft_toupper(p->map.tab[target.y][target.x]);
	}
	if ((c == 'L' && !(p->equiped & INV_KEY_Y)) || (c == 'M' &&
			!(p->equiped & INV_KEY_R)) || !char_in_str("GLM", c))
		return ;
	if (!(door_state(p, target.x, target.y)))
		set_door_state(p, target.x, target.y, 1);
	else if (door_state(p, target.x, target.y) == 3)
		set_door_state(p, target.x, target.y, 1);
}

void		move_sprite_toward_player(t_params *params, t_sprite *this)
{
	t_coord	spritepos;
	t_coord	spritedir;
	t_coord	delta;
	float	dist;

	spritepos.x = this->x;
	spritepos.y = this->y;
	delta.x = fabs(spritepos.x - params->pos.x);
	delta.y = fabs(spritepos.y - params->pos.y);
	update_sprite_health(params, this);
	dist = delta.x * delta.x + delta.y * delta.y;
	if (dist > 0.5)
	{
		spritedir = getangle(params->pos, spritepos);
		spritepos = spr_colision(params, spritepos, spritedir,
			params->movespeed * 0.75);
		sprite_interact(params, spritepos, spritedir);
		this->x = spritepos.x;
		this->y = spritepos.y;
	}
	else
		sprite_attack_player(params);
}
