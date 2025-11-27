/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:46:08 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 22:38:28 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	*fill_array(char *arr, size_t size, int n_aux, int n)
{
	while (size > 0)
	{
		arr[size - 1] = (n_aux % 10) + '0';
		n_aux = n_aux / 10;
		size--;
	}
	if (n < 0)
		arr[size] = '-';
	return (arr);
}

static void	*mem_alloc(char *arr, size_t len)
{
	arr = malloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	else
		return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;
	int		n_aux;

	n_aux = n;
	arr = NULL;
	size = nbr_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	arr = mem_alloc(arr, size);
	if (arr == NULL)
		return (NULL);
	if (n < 0)
		n_aux = -n_aux;
	arr[size] = '\0';
	arr = fill_array(arr, size, n_aux, n);
	return (arr);
}
