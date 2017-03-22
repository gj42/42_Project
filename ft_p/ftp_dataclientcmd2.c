/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_dataclientcmd2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 17:58:49 by gjensen           #+#    #+#             */
/*   Updated: 2016/02/19 19:33:23 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int	ftp_builtin_get_recv(int sock, int fd, int eol, int cr)
{
	char	buf[2];
	char	*lendata[2];
	int		ilen;

	lendata[0] = ft_strdup("");
	while (!eol)
	{
		if ((recv(sock, buf, 1, 0)) < 0)
			break ;
		buf[1] = 0;
		if (buf[0] == '\r')
			cr = 1;
		else if (cr == 1 && buf[0] == '\n')
			eol = 1;
		else if (cr && buf[0] != '\n')
			cr = 0;
		lendata[0] = ft_strjoinfree(lendata[0], buf);
	}
	ilen = ft_atoi(lendata[0]);
	lendata[1] = (char *)malloc(sizeof(char) * (ilen));
	if ((recv(sock, lendata[1], ilen, 0)) == -1)
		return (0);
	write(fd, lendata[1], ilen), ft_strdel(&lendata[0]);
	ft_strdel(&lendata[1]);
	return (1);
}

static int	ftp_builtin_get_msg(int sock, int *fd, char *str)
{
	char	*file;

	while (42)
	{
		write(1, "File already exists, replace it?(y/n)\n", 37);
		if (get_next_line(1, &file) != 1)
			return (0);
		if (ft_tolower(file[0]) == 'y')
		{
			ft_strdel(&file), write(sock, "y", 1);
			if ((*fd = open(str, O_CREAT | O_RDWR | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
				return (0);
			break ;
		}
		else if (ft_tolower(file[0]) == 'n')
		{
			ft_strdel(&file), write(sock, "n", 1);
			return (0);
		}
	}
	return (1);
}

static int	ftp_builtin_get_cut(int sock, char *str)
{
	int		fd;

	if ((fd = open(str, O_CREAT | O_RDWR | O_EXCL,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		if (!ftp_builtin_get_msg(sock, &fd, str))
		{
			close(fd);
			return (0);
		}
	}
	else
		write(sock, "y", 1);
	if (!ftp_builtin_get_recv(sock, fd, 0, 0))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static	int	ftp_builtin_get_filever(char *str, int sock)
{
	char	*full_cmd;
	char	*cmd;

	if (str)
	{
		if (ft_strstr(str, "..") || !ft_strncmp(str, "/", 1))
		{
			ft_putendl_fd("ERROR: File not valid", 2);
			return (0);
		}
		cmd = ft_strdup(str);
		full_cmd = ft_strjoin("RETR ", cmd);
		write(sock, full_cmd, ft_strlen(full_cmd) + 1);
		ft_strdel(&cmd);
		ft_strdel(&full_cmd);
	}
	else
	{
		ft_putendl("ERROR: Can't get this file");
		return (0);
	}
	return (1);
}

void		ftp_builtin_get(char **option, int sock)
{
	char	**cmd;
	int		i;
	char	msg[3];

	if (!ftp_builtin_get_filever(option[1], sock))
		return ;
	if (read(sock, msg, 3))
	{
		if (ft_strcmp(msg, "nf") == 0)
		{
			ft_putendl_fd("ERROR: Can't get this file", 2);
			return ;
		}
	}
	cmd = ft_strsplit(option[1], '/');
	i = ft_arrlen(cmd) - 1;
	if (ftp_builtin_get_cut(sock, cmd[i]))
		ft_putendl("SUCCESS: Data successfully copied");
	else
		ft_putendl_fd("ERROR: Can't get this data", 2);
	ft_arrfree(&cmd);
}
