/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:37 by boiarinov         #+#    #+#             */
/*   Updated: 2023/08/09 13:59:41 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	s_received = 0;

void	sig_error(void)
{
	ft_printf("Unexpected error\n");
	exit(EXIT_FAILURE);
}

void	binconv(unsigned char c, int pid)
{
	int				i;
	unsigned char	copy;

	i = 7;
	copy = 1u << i;
	while (copy)
	{
		s_received = 0;
		if (c & copy)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!s_received)
			pause();
		i--;
		copy >>= 1;
	}
}

void	message_sent(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		binconv(str[i++], pid);
	binconv('\0', pid);
}

void	message_received(int sig, siginfo_t *client, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		s_received = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Signal sent successfully\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	struct	sigaction sig;
	
	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = message_received;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
	{
		ft_printf("Error establishing PID\n");
		exit (EXIT_FAILURE);
	}
	ft_printf("Sending message...\n");
	message_sent(argv[2], server_pid);
	return (EXIT_SUCCESS);
}
