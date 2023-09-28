/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:50:28 by aboiarin          #+#    #+#             */
/*   Updated: 2023/09/28 14:48:18 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	*ft_memset(void *s, int c, size_t n);

#endif
