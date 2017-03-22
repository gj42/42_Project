/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_clientcmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 17:22:05 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/23 19:03:02 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	ftp_builtin_cd(char **option, int sock)
{
	char	*full_cmd;
	char	ret[4];

	if (option[1])
	{
		full_cmd = ft_joinarray(&option[1]);
		full_cmd = ft_strjoin("CWD ", full_cmd);
		write(sock, full_cmd, ft_strlen(full_cmd) + 1);
		ft_strdel(&full_cmd);
	}
	else
		write(sock, "CWD", 3);
	if (read(sock, ret, 4))
	{
		if (ft_strcmp(ret, "arg") == 0)
			ft_putendl_fd("ERROR: cd: Too many arguments", 2);
		else if (ft_strcmp(ret, "nof") == 0)
			ft_putendl_fd("ERROR: cd: Not a directory", 2);
		else if (ft_strcmp(ret, "err") == 0)
			ft_putendl_fd("ERROR: cd: Unexepected error occured", 2);
		else if (ft_strcmp(ret, "scc") == 0)
			ft_putendl("SUCCESS: Directory sucessfully changed");
	}
}

static void	ftp_builtin_ls(char **option, int sock)
{
	char	*full_cmd;

	if (option[1])
	{
		full_cmd = ft_joinarray(&option[1]);
		full_cmd = ft_strjoin("LIST ", full_cmd);
		write(sock, full_cmd, ft_strlen(full_cmd) + 1);
		ft_strdel(&full_cmd);
	}
	else
		write(sock, "LIST", 4);
}

int			ftp_client_cmd(int sock, char **option, int state, char *home)
{
	if (!option || !sock || !(*option))
		return (0);
	if (option[0])
	{
		if (ft_strcmp(ft_tomin(option[0]), "ls") == 0)
			ftp_builtin_ls(option, sock), state = 1;
		else if (ft_strcmp(ft_tomin(option[0]), "cd") == 0)
			ftp_builtin_cd(option, sock);
		else if (ft_strcmp(ft_tomin(option[0]), "pwd") == 0)
			write(sock, "PWD", 3), state = 1;
		else if (ft_strcmp(ft_tomin(option[0]), "quit") == 0)
			write(sock, "QUIT", 4), ft_putendl("SUCCESS: exit ok"), exit(0);
		else if (ft_strcmp(ft_tomin(option[0]), "get") == 0)
			ftp_builtin_get(option, sock);
		else if (ft_strcmp(ft_tomin(option[0]), "put") == 0)
			ftp_builtin_put(option, sock);
		else if ((ftp_local_cmd(option, home)))
			;
		else
			ft_putendl_fd("Command not found", 2);
	}
	return (state);
}
