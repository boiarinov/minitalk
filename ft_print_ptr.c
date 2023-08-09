/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:40:41 by aboiarin          #+#    #+#             */
/*   Updated: 2023/08/08 17:16:57 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_ptr_len(unsigned long n)
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

static void	ft_print_pbody(unsigned long n)
{
	if (n >= 16)
	{
		ft_print_pbody(n / 16);
		ft_print_pbody(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else
			ft_print_c((n - 10) + 'a');
	}
}

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	p;

	count = 0;
	if (ptr == 0)
		return (ft_print_str("(nil)"));
	p = (unsigned long)ptr;
	count += write(1, "0x", 2);
	ft_print_pbody(p);
	count += ft_ptr_len(p);
	return (count);
}
