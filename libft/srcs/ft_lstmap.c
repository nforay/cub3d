/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:12:38 by nforay            #+#    #+#             */
/*   Updated: 2020/02/01 16:27:46 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*ptr;

	if (!*lst || !del)
		return (NULL);
	tmp = *lst;
	while (tmp != NULL)
	{
		ptr = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = ptr;
	}
	*lst = NULL;
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*child;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	child = f(lst->content);
	if (!(new = ft_lstnew(child)))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		child = f(lst->content);
		if (!(tmp = ft_lstnew(child)))
			return (lstclear(&new, del));
		ft_lstadd_back(&new, tmp);
	}
	return (new);
}
