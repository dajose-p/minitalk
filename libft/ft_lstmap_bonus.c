/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:12:51 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 23:20:05 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lista;
	t_list	*aux_n;
	t_list	*nw_el;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	nw_el = ft_lstnew(f(lst->content));
	if (nw_el == NULL)
		return (NULL);
	n_lista = nw_el;
	aux_n = n_lista;
	lst = lst->next;
	while (lst != NULL)
	{
		nw_el = ft_lstnew(f(lst->content));
		if (nw_el == NULL)
		{
			ft_lstclear(&aux_n, del);
			return (NULL);
		}
		n_lista->next = nw_el;
		n_lista = nw_el;
		lst = lst->next;
	}
	return (aux_n);
}
