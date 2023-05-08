/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:45:30 by arigonza          #+#    #+#             */
/*   Updated: 2023/05/08 17:16:49 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send(int pid, char byte)
{
    int bit;

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

void    ft_hanldled(int signal)
{
    if (signal == SIGUSR1)
        ft_printf("message handled correctly");
}

int main(int argc, char** argv)
{
    int i;
    int pid;
    struct sigaction signal;

    if (argc!= 3)
    {
        ft_printf("Wrong number of arguments.\n");
        ft_printf("Try with the following format: ./client \"PID\" \"message\"")
        return (0);
    }
    pid = ft_atoi(argv[1]);
    signal.sa_hanlder = &ft_handled;
    sigaction(SIGUSR1, &signal, NULL);
    while (argv[2] != '\0')
        send(pid, argv[2][i++]);
    send(pid, argv[2][i]);

    return (0);
}
