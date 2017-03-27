# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 18:04:28 by gjensen           #+#    #+#              #
#    Updated: 2016/12/12 17:07:42 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LS = libft_malloc.so

CC = gcc
CFLAGS = -Werror -Wextra -Wall
CPATH = src/
INC = -I./includes -I./libft/includes
LIB = ./libft/libft.a
LINK = -Llibft -lft

CFILES = ft_malloc.c \
		 do_malloc.c \
		 free.c \
		 manage_page.c \
		 realloc.c \
		 show_alloc_mem.c \
		 print_adress.c



OPATH = obj/
OFILES = $(CFILES:.c=.o)

OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(LIB) $(NAME)

$(NAME):  $(OBJ)
	@echo "Making $(NAME)..."
	$(CC) -shared -o $(NAME) $^ $(LINK)
	ln -s $(NAME) $(LS)
	@echo "Done !"
	
$(OPATH)%.o: $(CPATH)%.c
	@mkdir -p $(OPATH)
	@echo "Making object..."
	$(CC) $(CFLAGS) -c $^ $(INC) -o $@
	@echo "Done !"

$(LIB):
	@echo "Compiling libft.."
	@make -C libft
	@echo "Done !"

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(LS)
	make -C ./libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
