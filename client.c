/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:37 by boiarinov         #+#    #+#             */
/*   Updated: 2023/08/09 16:51:30 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
}

void	binconv(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		ft_printf("Sending message...\n");
		while (argv[2][i] != '\0')
		{
			binconv(server_pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, check_received);
		binconv(server_pid, '\0');
	}
	else
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
