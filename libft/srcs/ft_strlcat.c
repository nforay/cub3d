/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:31:13 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 17:30:47 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!dest)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	k = ft_strlen(src);
	if (size <= i)
		k += size;
	else
		k += i;
	j = 0;
	while ((src[j] != '\0') && ((i + 1) < size))
		dest[i++] = src[j++];
	if (i < size)
		dest[i] = '\0';
	return (k);
}
