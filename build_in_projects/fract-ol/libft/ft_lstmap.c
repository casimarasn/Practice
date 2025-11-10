/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:13:48 by msedeno-          #+#    #+#             */
/*   Updated: 2025/05/17 16:38:19 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*node;
	t_list	*nobj;
	void	*ncontent;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	while (lst)
	{
		ncontent = f(lst->content);
		if (!ncontent)
			return (ft_lstclear(&node, del), NULL);
		nobj = ft_lstnew(ncontent);
		if (!nobj)
		{
			del(ncontent);
			return (ft_lstclear(&node, del), NULL);
		}
		ft_lstadd_back(&node, nobj);
		lst = lst->next;
	}
	return (node);
}
