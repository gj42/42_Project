#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 22:40:26 by gjensen           #+#    #+#              #
#    Updated: 2015/07/21 19:55:14 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
NAME_TEST = test

PATH_SRC = ./src/
AS = nasm
ASFLAGS = -f macho64
CC = cc -Wall -Wextra -Werror

LIBS = -L ./ -lfts

SRC = ft_bzero.s ft_strcat.s ft_isalpha.s ft_isalnum.s ft_isascii.s ft_isdigit.s ft_isprint.s \
	  ft_toupper.s ft_tolower.s ft_strlen.s ft_memset.s ft_memcpy.s ft_puts.s ft_strdup.s \
	  ft_cat.s ft_putchar.s ft_putchar_fd.s ft_islower.s ft_isupper.s ft_strcmp.s ft_putstr.s \
	  ft_strequ.s ft_strcpy.s ft_memalloc.s ft_strnew.s

OBJ = $(addprefix $(PATH_SRC), $(SRC:.s=.o))

.PHONY: clean fclean re test clean_test

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: $(OBJ) main.c
	$(CC) main.c $(LIBS) -o $(NAME_TEST) -g

clean_test:
	/bin/rm -f $(NAME_TEST)
