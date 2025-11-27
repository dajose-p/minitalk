/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 07:16:45 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/10 18:25:49 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(char const *buff, va_list ap, int i)
{
	if (*buff == 'c')
	{
		ft_putchar_fd((va_arg(ap, int)), 1);
		i++;
	}
	else if (*buff == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (*buff == 'd' || *buff == 'i')
		i += ft_putcount(va_arg(ap, int));
	else if (*buff == 'u')
		i += ft_putnuns(va_arg(ap, unsigned int));
	else if (*buff == 'x')
		i += ft_putcount_base(va_arg(ap, unsigned int));
	else if (*buff == 'X')
		i += ft_putcount_base_mayus(va_arg(ap, unsigned int));
	else if (*buff == 'p')
		i += ft_putcount_ptr(va_arg(ap, void *));
	else
	{
		ft_putchar_fd('%', 1);
		i++;
	}
	return (i);
}

int	ft_printf(char const *buff, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, buff);
	while (*buff)
	{
		if (*buff == '%')
		{
			buff++;
			i = ft_switch(buff, ap, i);
		}
		else
		{
			ft_putchar_fd(*buff, 1);
			i++;
		}
		buff++;
	}
	va_end(ap);
	return (i);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	int c;

	c = 0;
	c = ft_printf(" %p ", argv[1]);
	ft_printf(" %d ", c);
	return (0);
}*/
