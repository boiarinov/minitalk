/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:34:22 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/22 00:41:10 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binconv_reverse(int sig, siginfo_t *client, void *content)
{
	static int				bit = -1;
	static unsigned char	c;

	(void)content;
	if (bit < 0)
		bit = 7;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		write(1, &c, 1);
		c = 0;
		if (kill(client->si_pid, SIGUSR2) == -1)
		{
			ft_printf("Server failed to send SIGUSR2\n");
			return ;
		}
		if (kill(client->si_pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1\n");
	}
}

void	set_signals(void)
{
	struct sigaction	sa_signals;

	sa_signals.sa_sigaction = &binconv_reverse;
	sa_signals.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_signals, NULL) == -1)
		ft_printf("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa_signals, NULL) == -1)
		ft_printf("SIGUSR2 error\n");
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("Server started with PID: %d\n", pid);
	while (1)
		set_signals();
	return (EXIT_SUCCESS);
}
