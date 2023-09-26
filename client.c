/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:37 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/26 17:53:10 by aboiarin         ###   ########.fr       */
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

void	message_sent(int server_pid)
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

	ft_memset(&sa_signals, 0, sizeof(sa_signals));
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

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		ft_putstr("Sending message...\n");
		set_signals();
		send_message(server_pid, argv[2]);
		message_sent(server_pid);
	}
	else
	{
		ft_putstr("Use: ./client <server_pid> <message>\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
