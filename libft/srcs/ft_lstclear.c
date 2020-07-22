/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 02:16:46 by nforay            #+#    #+#             */
/*   Updated: 2020/02/20 16:39:06 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ptr;

	if (!*lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		ptr = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = ptr;
	}
	*lst = NULL;
}
