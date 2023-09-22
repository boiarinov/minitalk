/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:33:59 by boiarinov         #+#    #+#             */
/*   Updated: 2023/09/22 15:35:41 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

#endif
