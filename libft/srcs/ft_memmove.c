/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:34:01 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 16:25:01 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		tmp;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src < dest)
		while (n--)
		{
			tmp = s[n];
			d[n] = tmp;
		}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
