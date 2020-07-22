/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:04:57 by nforay            #+#    #+#             */
/*   Updated: 2020/07/06 02:01:17 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_image	*get_sprite_img_bonus(t_params *p, t_sprite *sprite)
{
	if (ft_toupper(sprite->texture) == 'P')
		return (&p->gunspr);
	else if (ft_toupper(sprite->texture) == 'Q')
		return (&p->ammos);
	else if (ft_toupper(sprite->texture) == 'R')
		return (&p->ammob);
	else if (ft_toupper(sprite->texture) == 'T')
		return (&p->healths);
	else if (ft_toupper(sprite->texture) == 'U')
		return (&p->healthb);
	else if (ft_toupper(sprite->texture) == 'V')
		return (&p->spritesolid);
	else if (ft_toupper(sprite->texture) == 'X')
		return (&p->nightv);
	else if (ft_toupper(sprite->texture) == 'Y')
		return (&p->key_y);
	else if (ft_toupper(sprite->texture) == 'Z')
		return (&p->key_r);
	else if (sprite->health <= 0 && p->spritedead.width != 0)
		return (&p->spritedead);
	else if (sprite->health < 10 && p->spriteexp.width != 0)
		return (&p->spriteexp);
	else
		return (&p->spritelive);
}

int		shade_sprite_color(t_params *p, t_spr_cast s, int color)
{
	if (!(BONUS))
		return (color);
	if (s.curr->hit == 1 && p->weaponcd > (int)(p->weaponbasecd * 0.75))
		return (shadedamagecolor(p, s.dist, color));
	else if (BONUS && s.dist > p->shadedist)
		return (shadecolor(p, s.dist, color));
	else
		return (shadecolor(p, p->shadedist, color));
}

int		sprite_hitscan(t_params *p, int x, int y)
{
	if (((x == (int)(p->w / 2) + 1) || (x == (int)(p->w / 2))) &&
			y == (int)(p->h / 2) && p->weaponcd == p->weaponbasecd &&
			!(ft_bufferstate(p, x, y)))
		return (1);
	return (0);
}
