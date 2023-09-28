/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:50:36 by aboiarin          #+#    #+#             */
/*   Updated: 2023/09/28 14:31:30 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_message(int sig, siginfo_t *client, void *msg)
{
	static int				bit = -1;
	static unsigned char	c;
	static int				client_pid;

	(void)msg;
	if (!client_pid || client_pid == 0)
		client_pid = client->si_pid;
	if (client_pid == client->si_pid)
	{
		if (bit < 0)
			bit = 7;
		if (sig == SIGUSR1)
			c |= (1 << bit);
		bit--;
		if (bit < 0)
		{
			write(1, &c, 1);
			if (c == '\0')
			{
				client_pid = 0;
				kill(client->si_pid, SIGUSR2);
			}
			c = 0;
		}
	}
	else
		kill(client->si_pid, SIGUSR1);
}

void	set_signals(void)
{
	struct sigaction	sa_signals;

	ft_memset(&sa_signals, 0, sizeof(sa_signals));
	sa_signals.sa_sigaction = &receive_message;
	sa_signals.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_signals, NULL) == -1)
		ft_putstr("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa_signals, NULL) == -1)
		ft_putstr("SIGUSR2 error\n");
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_putstr("Server started with PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
		set_signals();
	return (EXIT_SUCCESS);
}
