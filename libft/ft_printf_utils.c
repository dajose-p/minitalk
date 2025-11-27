/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:17:31 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/09 01:43:26 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_putcount(int n)
{
	char	*num;
	int		i;

	i = 0;
	num = NULL;
	num = ft_itoa(n);
	while (num[i] != '\0')
	{
		ft_putchar_fd(num[i], 1);
		i++;
	}
	free(num);
	return (i);
}

int	ft_putnuns(unsigned int n)
{
	char	*num;
	int		i;

	i = 0;
	num = NULL;
	num = ft_itoa_uns(n);
	while (num[i] != '\0')
	{
		ft_putchar_fd(num[i], 1);
		i++;
	}
	free(num);
	return (i);
}
