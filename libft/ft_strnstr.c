/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:36:56 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:37:13 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkneedl(const char *stack, const char *needl, size_t len)
{
	while (*stack == *needl && *needl && len > 0)
	{
		stack++;
		needl++;
		len--;
	}
	if (!(*needl))
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!haystack && !needle)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (ft_checkneedl(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
