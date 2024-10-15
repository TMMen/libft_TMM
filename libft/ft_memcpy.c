/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:45:53 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/16 15:44:39 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	const char	*temp_src;

	if (dst == src)
		return (dst);
	temp_dst = (char *)dst;
	temp_src = (const char *)src;
	while ((const void *)temp_src - src < (long)n)
		*temp_dst++ = *temp_src++;
	return (dst);
}
