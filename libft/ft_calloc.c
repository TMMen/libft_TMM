/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:56:43 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:35:39 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*store;
	size_t	i;

	if (((count * size) / size) != count)
		return (0);
	store = malloc(count * size);
	if (!store)
		return (0);
	i = 0;
	while (i < count * size)
	{
		store[i] = 0;
		i++;
	}
	return ((void *)store);
}
