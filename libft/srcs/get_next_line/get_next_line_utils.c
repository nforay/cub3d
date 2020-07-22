/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:07:09 by nforay            #+#    #+#             */
/*   Updated: 2020/06/13 18:58:34 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlentoc(const char *str, int c)
{
	size_t i;

	i = 0;
	if (!(str))
		return (0);
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

char	*ft_strmerge(char **s1, char *s2)
{
	char	*ptr;
	size_t	t1;
	size_t	t2;

	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen(*s1);
	t2 = ft_strlen(s2);
	if (!(ptr = malloc(t1 + t2 + 1)))
		return (NULL);
	ft_memcpy(ptr, *s1, t1);
	ft_memcpy((ptr + t1), s2, t2);
	ptr[(t1 + t2)] = '\0';
	ft_strdel(s1);
	*s1 = ptr;
	return (ptr);
}
