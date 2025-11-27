/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:24:29 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 20:52:47 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*aux;
	unsigned char	uc;

	uc = (unsigned char)c;
	aux = NULL;
	while (*s != '\0')
	{
		if (*s == uc)
			aux = s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)aux);
}
