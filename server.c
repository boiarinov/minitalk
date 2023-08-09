/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:34:22 by boiarinov         #+#    #+#             */
/*   Updated: 2023/08/08 23:42:17 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_error(void)
{
	ft_printf("Unexpected error\n");
	exit(EXIT_FAILURE);
}

void is_process_running(pid_t pid)
{
	if (kill(pid, 0) < 0)
	{
		ft_printf(("An error occured during the process, exiting...\n"), 1);
		exit(EXIT_FAILURE);
	}
}

void handler(int signal, siginfo_t *client, void *ucontext)
{
	(void)ucontext;
	static int shift = -1;
	static unsigned char c;

	is_process_running(client->si_pid);
	if (shift < 0)
		shift = 7;
	if (signal == SIGUSR1)
		c |= (1 << shift);
	shift--;
	if (shift < 0 && c)
	{
		ft_printf("%c", c);
		c = 0;
	}
	else if (shift < 0 && !c)
		kill(client->si_pid, SIGUSR2);
	kill(client->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;
	SA		sig;

	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = handler;
	sigemptyset(&(sig.sa_mask));
	pid = getpid();
	ft_printf("Server started with PID: %d\n", pid);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		sleep(1);
}
