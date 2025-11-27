/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:08:23 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/27 14:37:41 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_res(const char *nptr)
{
	int	res;

	res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res);
}

const char	*ft_isspace(const char *n)
{
	while (*n == ' ' || *n == '\t' || *n == '\n'
		|| *n == '\r' || *n == '\v' || *n == '\f')
		n++;
	return (n);
}

int	ft_atoi(const char *n)
{
	int	count;
	int	neg;
	int	res;

	count = 0;
	neg = 0;
	n = ft_isspace(n);
	while (*n == '+' || *n == '-')
	{
		if (*n == '+')
			count++;
		if (*n == '-')
		{
			count++;
			neg++;
		}
		n++;
	}
	if (count > 1)
		return (0);
	res = ft_res(n);
	if (neg == 1)
		res = -res;
	return (res);
}
