/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:38:10 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/09 16:28:31 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	*fill_array(char *arr, size_t size, unsigned int n_aux)
{
	while (size > 0)
	{
		arr[size - 1] = (n_aux % 10) + '0';
		n_aux = n_aux / 10;
		size--;
	}
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

char	*ft_itoa_uns(unsigned int n)
{
	char			*arr;
	int				size;
	unsigned int	n_aux;

	n_aux = n;
	arr = NULL;
	size = nbr_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	arr = mem_alloc(arr, size);
	if (arr == NULL)
		return (NULL);
	arr[size] = '\0';
	arr = fill_array(arr, size, n_aux);
	return (arr);
}
