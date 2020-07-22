/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:17:51 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 16:21:36 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	t1;
	size_t	t2;

	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	if (!(ptr = malloc(t1 + t2 + 1)))
		return (NULL);
	ft_memcpy(ptr, s1, t1);
	ft_memcpy((ptr + t1), s2, t2);
	ptr[(t1 + t2)] = '\0';
	return (ptr);
}
