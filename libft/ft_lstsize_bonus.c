/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:24:50 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 00:17:45 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cabeza;
	int		i;

	i = 0;
	cabeza = lst;
	while (cabeza != NULL)
	{
		cabeza = cabeza->next;
		i++;
	}
	return (i);
}
