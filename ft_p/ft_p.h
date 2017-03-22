/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 16:39:54 by gjensen           #+#    #+#             */
/*   Updated: 2015/07/21 23:54:15 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct stat	t_stat;
int		ftp_isbin(char *path);
int		ftp_acess(char *path);

/*
**fonctions serveur
*/

int		create_server(int port);
void	ftp_acceptclient(int sock);
void	ftp_read_socket(int cs);
void	ftp_putcmd(int cs, char *buf);
void	ftp_getcmd(int cs, char *buf);
char	*ftp_opt_ls(char *buf);

/*
**fonctions client
*/

int		ftp_client_cmd(int sock, char **option, int state, char *home);
void	ftp_builtin_get(char **option, int sock);
void	ftp_builtin_put(char **option, int sock);
void	ftp_cprompt(char *addr, int port);
int		ftp_local_cmd(char **cmd, char *home);
#endif
