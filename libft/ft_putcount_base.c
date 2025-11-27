/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcount_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:30:16 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/09 20:36:42 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned long n)
{
	static char		hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned int	r;

	r = 0;
	if (n >= 16)
		ft_putnbr_base(n / 16);
	r = (n % 16);
	write(1, &(hex[r]), 1);
}

int	ft_putcount_base(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putnbr_base(n);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	ft_putnbr_base_mayus(unsigned long n)
{
	static char		hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F'};
	unsigned int	r;

	r = 0;
	if (n >= 16)
		ft_putnbr_base_mayus(n / 16);
	r = (n % 16);
	write(1, &(hex[r]), 1);
}

int	ft_putcount_base_mayus(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_putnbr_base_mayus(n);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
