/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:49:04 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 00:41:47 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	aux;

	aux = (long long)n;
	c = '0';
	if (aux < 0)
	{
		write(fd, "-", 1);
		aux = -aux;
	}
	if (aux >= 10)
		ft_putnbr_fd(aux / 10, fd);
	c = ((aux % 10) + '0');
	write(fd, &c, 1);
}
