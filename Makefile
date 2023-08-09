# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: boiarinov <boiarinov@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 15:34:08 by boiarinov         #+#    #+#              #
#    Updated: 2023/08/09 16:50:09 by boiarinov        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -c -Wall -Werror -Wextra

RM = rm -f

SRC = ft_printf.c ft_print_char.c ft_print_hex.c ft_print_int.c \
ft_print_ptr.c ft_print_str.c ft_print_uint.c ft_calloc.c ft_atoi.c \
ft_strlen.c

all: start_message server client end_message

server: server.c
	@$(CC) $(CLFAGS) -o server server.c $(SRC)

client: client.c
	@$(CC) $(CLFAGS) -o client client.c $(SRC)

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