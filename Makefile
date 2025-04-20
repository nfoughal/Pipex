# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 16:54:34 by nfoughal          #+#    #+#              #
#    Updated: 2022/12/20 15:27:48 by nfoughal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC  = pipex.c utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

${NAME} : ${OBJ}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJ} -Llibft -lft -o ${NAME}
	
clean:
	rm -f $(OBJ)
	${MAKE} clean -C ./libft

fclean: clean
	rm -f $(NAME)
	${MAKE} fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
