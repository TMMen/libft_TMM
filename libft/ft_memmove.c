/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:16:51 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/16 17:07:05 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_temp;

	if (dst > src)
	{
		dst_temp = (char *)dst + len - 1;
		src = src + len - 1;
		while (dst_temp >= (char *)dst)
			*dst_temp-- = *(char *)src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
