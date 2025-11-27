/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajose-p <dajose-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:11:40 by dajose-p          #+#    #+#             */
/*   Updated: 2024/10/01 00:20:37 by dajose-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*mylist;

	mylist = malloc(sizeof(t_list));
	if (mylist == NULL)
		return (NULL);
	mylist->content = (void *)content;
	mylist->next = NULL;
	return (mylist);
}
