/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 07:40:48 by dajose-p          #+#    #+#             */
/*   Updated: 2024/11/09 20:37:45 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(char const *buff, ...);
int		ft_putstr(char *str);
int		ft_putcount(int n);
int		ft_putnuns(unsigned int n);
char	*ft_itoa_uns(unsigned int n);
int		ft_putcount_base(unsigned long n);
int		ft_putcount_base_mayus(unsigned long n);
int		ft_putcount_ptr(void *ptr);

#endif
