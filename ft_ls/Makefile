# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 10:48:25 by gjensen           #+#    #+#              #
#    Updated: 2015/04/01 16:00:37 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c main.c tool.c tool2.c long.c long2.c managestart.c argmanage.c recursive.c

OBJ = ft_ls.o main.o tool.o tool2.o long.o long2.o managestart.o argmanage.o recursive.o

CFLAGS = -Werror -Wall -Wextra

LIB = -I ./libft/includes

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAGS) -c $(SRC) $(LIB) -g
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft -g

all: $(NAME)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
