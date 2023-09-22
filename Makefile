# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 15:34:08 by boiarinov         #+#    #+#              #
#    Updated: 2023/09/22 17:32:23 by aboiarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra

RM = rm -f

SRC = ft_putstr.c ft_atoi.c ft_itoa.c

all: start_message server client end_message

server: server.c
	@$(CC) $(CFLAGS) -o server server.c $(SRC)

client: client.c
	@$(CC) $(CFLAGS) -o client client.c $(SRC)

clean:
	@$(RM) server client
	@echo 'Executables removed ✨'

start_message:
	@echo 'Compiling... 🌊'

end_message:
	@echo 'Done ✅'

re_message:
	@echo 'Starting over... ⏪'

fclean:	clean

re: re_message fclean all

.PHONY: all server client clean fclean re start_message re_message end_message