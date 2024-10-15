/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:19:18 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:37:23 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*store;
	unsigned int	slen;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		start = slen;
	if (start + len >= slen)
		len = slen - start;
	if (len + 1 == 0)
		len++;
	store = (char *)malloc((len + 1) * sizeof(char));
	if (!store)
		return (NULL);
	i = 0;
	while (i < (unsigned int)len)
	{
		store[i] = s[i + start];
		i++;
	}
	store[i] = '\0';
	return (store);
}
