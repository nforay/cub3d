/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_interact_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:07:58 by nforay            #+#    #+#             */
/*   Updated: 2020/07/03 20:00:53 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	player_pickup_gun(t_params *params, t_sprite *this)
{
	params->equiped |= INV_GUN;
	params->shadecol.b = 3;
	params->ammo += 30;
	params->ammo = (params->ammo > 500 ? 500 : params->ammo);
	this->health = 0;
	ft_putchar_fd(7, 1);
}

static void	player_pickup_ammo(t_params *params, t_sprite *this)
{
	params->ammo += (this->texture == 2 ? 100 : 35);
	params->ammo = (params->ammo > 500 ? 500 : params->ammo);
	params->shadecol.b = 3;
	this->health = 0;
	ft_putchar_fd(7, 1);
}

static void	player_pickup_health(t_params *params, t_sprite *this)
{
	params->health += (this->texture == 4 ? 50 : 15);
	params->health = (params->health > 100 ? 100 : params->health);
	params->shadecol.g = 3;
	this->health = 0;
	ft_putchar_fd(7, 1);
}

static void	player_pickup_item(t_params *params, t_sprite *this)
{
	if (ft_toupper(this->texture) == 'X' && this->health)
	{
		params->greyscale = 1;
	}
	else if (ft_toupper(this->texture) == 'Y' && this->health)
	{
		params->equiped |= INV_KEY_Y;
		params->shadecol.r = 3;
		params->shadecol.g = 3;
	}
	else if (ft_toupper(this->texture) == 'Z' && this->health)
	{
		params->equiped |= INV_KEY_R;
		params->shadecol.r = 3;
	}
	ft_putchar_fd(7, 1);
	this->health = 0;
}

void		perform_sprites_interactions(t_params *params, int i)
{
	t_sprite	*this;

	while (i < params->map.n_sprite)
	{
		this = &params->map.sprite[params->map.s_order[i]];
		if (ft_toupper(this->texture) == 'O' && params->map.s_dist[i] < 4)
			this->active = 1;
		if (ft_toupper(this->texture) > 'O' && params->map.s_dist[i] < 0.5)
		{
			if (ft_toupper(this->texture) == 'P' && this->health)
				player_pickup_gun(params, this);
			else if (this->health && ft_toupper(this->texture) < 'T' &&
					params->ammo < 500)
				player_pickup_ammo(params, this);
			else if (this->health && ft_toupper(this->texture) < 'V' &&
					params->health < 100)
				player_pickup_health(params, this);
			else if (char_in_str("VXYZ", ft_toupper(this->texture)))
				player_pickup_item(params, this);
		}
		else if (this->active && this->health > 0)
			move_sprite_toward_player(params, this);
		i++;
	}
}
