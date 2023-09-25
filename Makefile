# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboiarin <aboiarinstudent.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 15:34:08 by boiarinov         #+#    #+#              #
#    Updated: 2023/09/25 14:47:06 by aboiarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME_S = server
NAME_C = client

SRC_S = server.c server_utils.c
SRC_C = client.c client_utils.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: start_message $(NAME_S) $(NAME_C) success_message

.o:		.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME_S):	$(OBJ_S)
	@$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)
	@echo 'Server ready ✅'

$(NAME_C):	$(OBJ_C)
	@$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
	@echo 'Client ready ✅'

clean:
	@$(RM) $(OBJ_S) $(OBJ_C)
	@echo 'Object files removed ✨'

start_message:
	@echo 'Compiling... 🌊'

success_message:
	@echo 'Done ✅'

re_message:
	@echo 'Starting over... ⏪'

fclean:	clean
		@$(RM) $(NAME_S) $(NAME_C)
		@echo 'Executables removed ✨'

re: re_message fclean all

.PHONY: all clean fclean re
