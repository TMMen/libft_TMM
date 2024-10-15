/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenzel <tmenzel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:28:24 by tmenzel           #+#    #+#             */
/*   Updated: 2023/12/11 18:36:39 by tmenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	b_to_power_e(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent-- > 0)
		result = result * base;
	return (result);
}

static int	ft_count_digits(int n)
{
	int	i;
	int	digitcount;

	if (n == -2147483648)
		return (11);
	digitcount = 0;
	if (n < 0)
	{
		n = -n;
		digitcount++;
	}
	i = 1;
	while (b_to_power_e(10, i) <= n && i < 10)
		i++;
	digitcount += i;
	return (digitcount);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	store_char;
	int		digitcount;
	int		i;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		digitcount = ft_count_digits(n);
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			digitcount--;
		}
		i = 1;
		while (i <= digitcount)
		{
			store_char = (n / b_to_power_e(10, digitcount - i) % 10) + '0';
			write(fd, &store_char, 1);
			i++;
		}
	}
}
