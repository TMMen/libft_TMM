/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:25:08 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:36:58 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*store;
	int		length1;
	int		length2;
	int		i;

	length1 = ft_strlen(s1);
	length2 = ft_strlen(s2);
	if (length1 + length2 + 1 == 0)
		return (0);
	store = (char *)malloc((length1 + length2 + 1) * sizeof(char));
	if (!store)
		return (0);
	i = 0;
	while (i < length1)
	{
		store[i] = s1[i];
		i++;
	}
	while (i - length1 < length2)
	{
		store[i] = s2[i - length1];
		i++;
	}
	store[i] = '\0';
	return (store);
}
