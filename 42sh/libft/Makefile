#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/08/16 09:21:46 by bciss             #+#    #+#              #
#    Updated: 2016/05/16 12:04:34 by bciss            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CFILES = \
	ft_arrfree.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_countc.c \
	ft_dblstrnew.c \
	ft_hextodec.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_ishexa.c \
	ft_isocta.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_octtodec.c \
	ft_pow.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_cr.c \
	ft_putendl_db.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_cr.c \
	ft_putstr_fd.c \
	ft_puttab.c \
	ft_replace_char.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcjoin.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strsupertrim.c \
	ft_strtrim.c \
	ft_swapstr.c \
	ft_tablen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strremovechars.c \
	ft_arrlen.c \
	ft_joinarray.c \
	ft_arrcpy.c	\
	ft_strdupcign.c \
	ft_strlencign.c \
	ft_strdupc.c \
	ft_strlenc.c \
	ft_strlchr.c \
	ft_tablen.c \
	ft_strlcpy.c

OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re
.SILENT:

$(NAME): all

all: $(OFILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

%.o: %.c ../inc/libft.h
	$(CC) $(CFLAGS) $< -c -I ../inc/ -o $@

clean:
	rm -rf $(OFILES)
fclean: clean
	rm -rf $(NAME)

re: fclean all
