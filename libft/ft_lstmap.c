/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:23:29 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:52:39 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*curr;
	t_list	*new;

	if (!lst)
		return (NULL);
	root = ft_lstnew((*f)(lst->content));
	if (!root)
		return (NULL);
	curr = lst->next;
	while (curr != NULL)
	{
		new = ft_lstnew((*f)(curr->content));
		if (!new)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		ft_lstadd_back(&root, new);
		curr = curr->next;
	}
	return (root);
}
