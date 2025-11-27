/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:27:38 by dajose-p          #+#    #+#             */
/*   Updated: 2024/09/30 23:28:46 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cabeza;

	if (lst == NULL)
		return (NULL);
	cabeza = lst;
	while ((cabeza->next) != NULL)
		cabeza = cabeza->next;
	return (cabeza);
}
