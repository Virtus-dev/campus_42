/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arigonza <arigonza@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:46:05 by arigonza          #+#    #+#             */
/*   Updated: 2023/05/08 16:38:23 by arigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_display(int signal, siginfo_t *info, void *useless)
{
    void                    *useless;
    static unsigned char    byte;
    static int              bit;

    if (signal == SIGUSR1)
        byte = byte | (1 << bit);
    bit++;
    if (bit == 8)
    {
        if (byte == '\0')
        {
            ft_print("\n"");
            kill(info->is_pid, SIGUSR1);
        }
        else
            printf("%c", byte);
        byte = 0;
        bit = 0;
    }
}

int main(void)
{
    int                 pid;
    struct signation    data;

    pid = getpid();

    data.sa_sigaction = &ft_display;
    data.sa_flags = SA_SIGINFO;
    ft_printf("Welcome to minitalk\n Use this PID int the client side to start sending messages: %d", pid);
    while (1)
    {
        sigaction(SIGUSR1, &data, NULL);
        sigaction(SIGUSR2, &data, NULL);
    }
    return (0);
}
