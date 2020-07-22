/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:52:47 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 16:21:41 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*pointeur;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(pointeur = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		pointeur[i] = src[i];
		i++;
	}
	pointeur[i] = '\0';
	return (pointeur);
}
