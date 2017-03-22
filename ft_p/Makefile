#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 19:18:07 by gjensen           #+#    #+#              #
#    Updated: 2015/07/25 19:33:00 by gjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVEUR = serveur

CLIENT = client

SRCSERV = serveur.c createserv.c ftp_servcmd.c ftp_dataservcmd.c ftp_tool.c ftp_dataservcmd2.c

SRCCL = client.c ftp_clientcmd.c ftp_dataclientcmd.c ftp_tool.c ftp_dataclientcmd2.c ftp_localclientcmd.c

OBJSERV = $(SRCSERV:.c=.o)

OBJCL = $(SRCCL:.c=.o)

#CFLAGS = -I libft/includes -g
CFLAGS = -Werror -Wextra -Wall -I libft/includes

all: client serveur

$(SERVEUR): $(OBJSERV)
	make -C libft/
	gcc $(CFLAGS) -o $(SERVEUR) $(OBJSERV) -L libft/ -lft

$(CLIENT): $(OBJCL)
	make -C libft/
	gcc $(CFLAGS) -o $(CLIENT) $(OBJCL) -L libft/ -lft

clean:
	rm -rf $(OBJSERV) $(OBJCL)

fclean: clean
	rm -rf $(SERVEUR) $(CLIENT)
	Make -C libft/ fclean

re:	fclean all

.PHONY: all clean fclean re
