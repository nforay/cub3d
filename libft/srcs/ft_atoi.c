/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:08:42 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 16:30:57 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	int		i;
	int		pos;

	i = 0;
	result = 0;
	pos = 1;
	while ((str[i] == ' ') || (str[i] == '\v') || (str[i] == '\t') ||
			(str[i] == '\f') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos = 0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	if (pos)
		return (result);
	else
		return (-result);
}
