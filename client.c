/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:37 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/22 00:35:18 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
}

void	binconv(int server_pid, char *msg)
{
	unsigned char	c;
	int				i;

	while (*msg)
	{
		c = *msg;
		i = 8;
		while (i--)
		{
			if (c & 0b10000000)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(50);
			c <<= 1;
		}
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
}

void	set_signals(void)
{
	struct sigaction	sa_signals;

	sa_signals.sa_handler = &sig_handler;
	sa_signals.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_signals, NULL) == -1)
		ft_printf("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa_signals, NULL) == -1)
		ft_printf("SIGUSR2 error\n");
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		set_signals();
		ft_printf("Sending message...\n");
		binconv(server_pid, argv[2]);
		signal(SIGUSR2, check_received);
	}
	else
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
