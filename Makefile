# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 16:43:48 by cpalmier          #+#    #+#              #
#    Updated: 2017/12/06 13:57:30 by mpasquie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= src/algo.c \
		  src/verif_algo.c \
		  src/check_tris.c \
		  src/create_config.c \
		  src/create_tris.c \
		  src/fillit.c \
		  src/grid_op.c \
		  src/main.c \
		  src/read_file.c 

OBJ		= $(SRC:.c=.o)

INCLUDE	= include/fillit.h \
		  include/libft.h

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C Libft
	gcc -Wall -Werror -Wextra $(OBJ) Libft/Libft.a -o $(NAME)

./%.o: src/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	make -C Libft fclean

re: fclean all
	make -C Libft re
