/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:37 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/25 15:18:53 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int server_pid, char *msg)
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
		msg++;
	}
}

void	send_null(int server_pid)
{
	int				i;

	i = 8;
	while (i--)
	{
		kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

void	check_status(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("Message received\n");
	else if (sig == SIGUSR1)
	{
		ft_putstr("Server is busy!\n");
		exit(1);
	}
}

void	set_signals(void)
{
	struct sigaction	sa_signals;

	sa_signals.sa_handler = &check_status;
	sa_signals.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_signals, NULL) == -1)
		ft_putstr("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa_signals, NULL) == -1)
		ft_putstr("SIGUSR2 error\n");
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	set_signals();
	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		ft_putstr("Sending message...\n");
		send_message(server_pid, argv[2]);
		send_null(server_pid);
	}
	else
	{
		ft_putstr("Usage: ./client <server_pid> <message>\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
