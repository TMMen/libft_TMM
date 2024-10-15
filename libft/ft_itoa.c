/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:59:10 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:35:49 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int ft_digitcounter(int n)
{
	unsigned int	digitcount;

	digitcount = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		digitcount++;
	}
	return (digitcount);
}

char	*ft_itoa(int n)
{
	unsigned int	digits;
	unsigned int	minus;
	char			*str;

	minus = 0;
	if (n < 0)
		minus = 1;
	digits = ft_digitcounter(n);
	str = malloc(sizeof(char) * (digits + minus + 1));
	if (!str)
		return (0);
	str[digits + minus] = '\0';
	while (digits)
	{
		if (n > 0)
			str[digits + minus - 1] = n % 10 + '0';
		else
			str[digits + minus - 1] = -(n % 10) + '0';
		n /= 10;
		digits--;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}
