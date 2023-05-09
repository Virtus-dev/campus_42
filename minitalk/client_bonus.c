/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza < arigonza@student.42malaga.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:50:49 by arigonza          #+#    #+#             */
/*   Updated: 2023/05/09 16:53:28 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char byte)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((byte & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit++;
	}
}

void	ft_handled(int signal)
{
	if (signal == SIGUSR1)
		ft_printf(FBLUE "message handled correctly\n" NONE);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = -1;
	if (argc != 3)
	{
		ft_printf(FRED "Wrong number of arguments.\n");
		ft_printf("Try with the following format: ./client \"PID\" \"message\"\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_handled);
	while (argv[2][++i])
		send(pid, argv[2][i]);
	send(pid, '\0');
	return (0);
}
