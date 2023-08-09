/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:59 by boiarinov         #+#    #+#             */
/*   Updated: 2023/08/09 16:50:11 by boiarinov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define SA struct sigaction

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

int		ft_printf(const char *format, ...);

int		ft_print_char(char c);
int		ft_print_c(char c);
int		ft_print_str(char *str);
int		ft_print_int(long n);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int x, char xcase);
int		ft_print_ptr(void *ptr);

#endif
