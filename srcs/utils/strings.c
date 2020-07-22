/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:44:28 by nforay            #+#    #+#             */
/*   Updated: 2020/07/11 16:21:29 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_tab(char **a, t_icoord size)
{
	int i;
	int j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (a[i][j] == 'F')
				ft_putstr_fd("\033[1;31m", 1);
			else if (char_in_str("NSEW", a[i][j]))
				ft_putstr_fd("\033[1;32m", 1);
			else if (!reachable(a, i, j))
				ft_putstr_fd("\033[1;34m", 1);
			ft_putchar_fd(a[i][j], 1);
			ft_putstr_fd("\033[0;0m", 1);
			j++;
		}
		i++;
		ft_putchar_fd('\n', 1);
	}
	ft_putchar_fd('\n', 1);
}

int		char_in_str(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

int		is_interior(int c)
{
	if ((c >= 'a') && (c <= 'm'))
		return (1);
	else if (c >= '1' && c <= '7')
		return (1);
	return (0);
}
