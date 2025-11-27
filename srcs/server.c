/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:42:39 by danjose-          #+#    #+#             */
/*   Updated: 2025/11/27 18:51:42 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>

int main(void)
{
	int	i;
	for (i=1; i<=64; i++)
		signal(i, trapper);
	printf("Process ID is: %d\n", getpid());
	pause();

	return (0);
}
