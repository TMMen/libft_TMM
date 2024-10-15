/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:11 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:35:57 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*store;

	while (*lst != NULL)
	{
		store = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = store;
	}
	lst = NULL;
}
