/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcount_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:26:03 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/09 20:34:40 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcount_ptr(void *ptr)
{
	unsigned long	ul;
	int				c;

	ul = (unsigned long)ptr;
	c = 0;
	if (!ptr)
	{
		c += ft_putstr("(nil)");
		return (c);
	}
	c += ft_putstr("0x");
	c += ft_putcount_base(ul);
	return (c);
}
