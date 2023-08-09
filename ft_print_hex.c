/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:41:23 by aboiarin          #+#    #+#             */
/*   Updated: 2023/08/08 17:16:57 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_print_xbody(unsigned int x, char xcase)
{
	if (x >= 16)
	{
		ft_print_xbody(x / 16, xcase);
		ft_print_xbody(x % 16, xcase);
	}
	else
	{
		if (x <= 9)
			ft_print_c((x + '0'));
		else
		{
			if (xcase == 'x')
				ft_print_c((x - 10 + 'a'));
			if (xcase == 'X')
				ft_print_c((x - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int x, char xcase)
{
	int		count;

	count = 0;
	if (x == 0)
	{
		count += ft_print_str("0");
		return (count);
	}
	ft_print_xbody(x, xcase);
	return (ft_hex_len(x));
}
