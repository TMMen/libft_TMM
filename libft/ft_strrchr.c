/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:38:35 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/04 18:09:51 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp_s;

	temp_s = NULL;
	while (*s)
	{
		if (*s == (char)c)
			temp_s = s;
		s++;
	}
	if ((char)c == '\0')
		temp_s = s;
	return ((char *)temp_s);
}
