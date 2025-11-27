/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:59:22 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 00:07:16 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cabeza;
	t_list	*next;

	cabeza = *lst;
	while (cabeza != NULL)
	{
		next = cabeza->next;
		ft_lstdelone(cabeza, del);
		cabeza = next;
	}
	*lst = NULL;
	free(*lst);
}
