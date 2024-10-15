/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:01:24 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:54:04 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(const char *str, const char *set)
{
	while (*set)
	{
		if (*set == *str)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		size;

	while (ft_check_set(s1, set))
		s1++;
	size = (int)ft_strlen(s1);
	while (size > 0)
	{
		if (ft_check_set(s1 + size - 1, set))
			size--;
		else
			break ;
	}
	newstr = (char *)malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, size + 1);
	return (newstr);
}
