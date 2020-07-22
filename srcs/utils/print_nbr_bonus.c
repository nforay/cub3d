/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:41:20 by nforay            #+#    #+#             */
/*   Updated: 2020/07/03 02:37:07 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_printnbr(int nbr, int x, int y, t_params *params)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	h;
	unsigned int	w;

	if (nbr > 1)
		start = 32 + (nbr - 2) * 20;
	else if (nbr == 1)
		start = 20;
	else
		start = 0;
	end = (nbr == 1 ? 32 : start + 20);
	h = 0;
	while (h < 16)
	{
		w = start;
		while (w < end)
		{
			my_mlx_pixel_put_bl(&params->img, x + w - start, y + h,
				getpixelcolor(&params->font, w, h));
			w++;
		}
		h++;
	}
}

void	ft_printnbr_rtl(unsigned int nbr, int x, int y, t_params *params)
{
	if (nbr <= 9)
		ft_printnbr(nbr, x + (nbr == 1 ? 8 : 0), y, params);
	else
	{
		ft_printnbr(nbr % 10, x + (nbr % 10 == 1 ? 8 : 0), y, params);
		x -= (nbr % 10 == 1 ? 12 : 20);
		ft_printnbr_rtl(nbr / 10, x, y, params);
	}
}
