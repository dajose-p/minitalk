/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:05:18 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 22:24:35 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mem_alloc(char *arr, size_t len)
{
	arr = malloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	else
		return (arr);
}

void	*assign_func(char *str, char const *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = NULL;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = mem_alloc(str, 0);
		if (str == NULL)
			return (NULL);
		if (str != 0)
			str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = mem_alloc(str, len);
	if (str == NULL)
		return (NULL);
	str = assign_func(str, s, len, start);
	return (str);
}
