# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/10 13:00:33 by gjensen           #+#    #+#              #
#    Updated: 2015/03/26 15:01:12 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c fdf.c parsearg.c tool.c draw.c

OBJ = $(SRC:.c=.o)

CFLAFGS = -Werror -Wextra -Wall

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAGS) -c $(SRC) -I ./libft/includes -g
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -lmlx -framework OpenGL -framework AppKit -L libft -lft -g

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
