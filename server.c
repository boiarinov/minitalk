/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:34:22 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/21 13:40:47 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binconv_reverse(int sig, siginfo_t *client, void *context)
{
	int	bit;
	int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(client->si_pid, SIGUSR2);
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	SA		sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Unexpected error\n");
		return (EXIT_FAILURE);
	}
	pid = getpid();
	ft_printf("Server started with PID: %d\n", pid);
	sig.sa_sigaction = binconv_reverse;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (EXIT_SUCCESS);
}
