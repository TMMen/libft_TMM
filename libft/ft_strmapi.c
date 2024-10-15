/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:37 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:37:08 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*store;
	int		i;

	store = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!store)
		return (NULL);
	i = 0;
	while (s[i])
	{
		store[i] = (*f)(i, s[i]);
		i++;
	}
	store[i] = '\0';
	return (store);
}
