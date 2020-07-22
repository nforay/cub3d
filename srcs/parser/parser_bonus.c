/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:24:49 by nforay            #+#    #+#             */
/*   Updated: 2020/07/12 18:00:24 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_bonus_next(t_params *tmp, char *line)
{
	double	nbr;

	if (!ft_strncmp(line, "SP ", 3))
	{
		tmp->movespeed = ((double)ft_atoi_basic(line + 3) / 100);
		return (1);
	}
	else if (!ft_strncmp(line, "LU ", 3))
	{
		tmp->shadedist = ((double)ft_atoi_basic(line + 3) / 10);
		return (1);
	}
	else if (!ft_strncmp(line, "ROT ", 4) &&
		(nbr = (double)ft_atoi_basic(line + 4)) > 0)
	{
		nbr /= 1000;
		tmp->cosr = cos(nbr);
		tmp->cosmr = cos(-nbr);
		tmp->sinr = sin(nbr);
		tmp->sinmr = sin(-nbr);
		return (1);
	}
	return (parse_error("Element missing or unknown."));
}

static int	parse_bonus_textures(t_params *tmp, char *line)
{
	if (!ft_strncmp(line, "IAD ", 4))
		return (load_texture(tmp, &tmp->spritedead, line + 4, 0));
	else if (!ft_strncmp(line, "KY ", 3))
		return (load_texture(tmp, &tmp->key_y, line + 3, 0));
	else if (!ft_strncmp(line, "KR ", 3))
		return (load_texture(tmp, &tmp->key_r, line + 3, 0));
	else if (!ft_strncmp(line, "SS ", 3))
		return (load_texture(tmp, &tmp->spritesolid, line + 3, 0));
	else if (!ft_strncmp(line, "WT ", 3))
		return (load_texture(tmp, &tmp->walltex, line + 3, 0));
	else if (!ft_strncmp(line, "CT ", 3))
		return (load_texture(tmp, &tmp->cylindtex, line + 3, 0));
	else if (!ft_strncmp(line, "PW ", 3))
		return (load_texture(tmp, &tmp->pushwall, line + 3, 0));
	return (parse_bonus_next(tmp, line));
}

int			parse_bonus(t_params *tmp, char *line)
{
	if (!ft_strncmp(line, "FT ", 3) || !ft_strncmp(line, "SK ", 3))
		return (parse_texture(tmp, line));
	else if (!ft_strncmp(line, "DT ", 3))
		return (load_texture(tmp, &tmp->doortex, line + 3, 0));
	else if (!ft_strncmp(line, "DY ", 3))
		return (load_texture(tmp, &tmp->doortex_y, line + 3, 0));
	else if (!ft_strncmp(line, "DR ", 3))
		return (load_texture(tmp, &tmp->doortex_r, line + 3, 0));
	else if (!ft_strncmp(line, "OFT ", 4))
		return (load_texture(tmp, &tmp->floortex, line + 4, 0));
	else if (!ft_strncmp(line, "DF ", 3))
		return (load_texture(tmp, &tmp->doorframetex, line + 3, 0));
	else if (!ft_strncmp(line, "DFY ", 4))
		return (load_texture(tmp, &tmp->doorframetex_y, line + 4, 0));
	else if (!ft_strncmp(line, "DFR ", 4))
		return (load_texture(tmp, &tmp->doorframetex_r, line + 4, 0));
	else if (!ft_strncmp(line, "DF ", 3))
		return (load_texture(tmp, &tmp->doorframetex, line + 3, 0));
	else if (!ft_strncmp(line, "IA ", 3))
		return (load_texture(tmp, &tmp->spritelive, line + 3, 0));
	else if (!ft_strncmp(line, "IAH ", 4))
		return (load_texture(tmp, &tmp->spriteexp, line + 4, 0));
	return (parse_bonus_textures(tmp, line));
}
