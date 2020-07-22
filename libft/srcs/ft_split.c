/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:48:11 by nforay            #+#    #+#             */
/*   Updated: 2020/02/24 17:56:46 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		splitnbr(const char *str, char c)
{
	size_t	i;
	size_t	score;
	size_t	j;

	i = 0;
	score = 0;
	while (str[i])
	{
		if (c == str[i])
		{
			i++;
			continue ;
		}
		j = i + 1;
		while ((c != str[j]) && str[j])
			j++;
		score++;
		i = j;
		if (str[i] == '\0')
			return (score);
		i++;
	}
	return (score);
}

static void			*abort_split(char **splitted, size_t n)
{
	while (n--)
	{
		free(splitted[n]);
		splitted[n] = NULL;
	}
	free(splitted);
	splitted = NULL;
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splitted;
	size_t	n;

	if (!s)
		return (NULL);
	if (!(splitted = ft_calloc(splitnbr(s, c) + 1, sizeof(splitted))))
		return (NULL);
	n = 0;
	i = 0;
	while (s[i] && (splitnbr(s, c) > 0))
		if (c != s[i])
		{
			j = i + 1;
			while (c != s[j] && s[j])
				j++;
			if (!(splitted[n++] = ft_substr(s, i, j - i)))
				return (abort_split(splitted, n - 1));
			i = j;
		}
		else
			i++;
	splitted[n] = NULL;
	return (splitted);
}
