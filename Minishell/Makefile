# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/01 15:26:04 by gjensen           #+#    #+#              #
#    Updated: 2015/05/13 14:39:48 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

SRC = main.c command.c envmanage.c sh_builtins.c sh_builtin_cd.c sh_builtin_env.c sh_builtin_setenv.c sh_builtin_unsetenv.c signals.c \
	  childsignals.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall -I libft/includes -g
#CFLAGS = -I libft/includes -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all re fclean clean
