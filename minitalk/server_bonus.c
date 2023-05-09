/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:55:59 by arigonza          #+#    #+#             */
/*   Updated: 2023/05/09 16:56:07 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_display(int signal, siginfo_t *info, void *useless)
{
	static unsigned char	byte;
	static int				bit;

	(void)useless;
	if (signal == SIGUSR1)
		byte = byte | (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", byte);
		byte = 0;
		bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	data;

	pid = getpid();
	data.sa_sigaction = &ft_display;
	data.sa_flags = SA_SIGINFO;
	ft_printf(FGREEN "Welcome to minitalk\n");
	ft_printf("Use this PID for Minitalk: %d\n"NONE, pid);
	while (1)
	{
		sigaction(SIGUSR1, &data, NULL);
		sigaction(SIGUSR2, &data, NULL);
		pause();
		usleep(50);
	}
	return (0);
}
