/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:24:24 by tmenzel           #+#    #+#             */
/*   Updated: 2023/11/16 16:14:59 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	if (!s)
		return ;
	str = (char *)s;
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
