/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:42:39 by danjose-          #+#    #+#             */
/*   Updated: 2025/12/02 00:01:20 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t	g_data = 0;

void	signal_handler(int signal)
{
	int		bit_count;
	char	curr_char;

	bit_count = (g_data >> 8) & 0xFF;
	curr_char = g_data & 0XFF;
	if (signal == SIGUSR2)
		curr_char |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &curr_char, 1);
		curr_char = 0;
		bit_count = 0;
	}
	g_data = (bit_count << 8) | curr_char;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process ID is: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	pause();
	return (0);
}
