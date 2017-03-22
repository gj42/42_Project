/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_dataclientcmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 22:49:06 by gjensen           #+#    #+#             */
/*   Updated: 2016/02/19 19:33:01 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int	ftp_builtin_put_send(int sock, char **av)
{
	int		fd;
	char	*len;
	char	*buf;
	t_stat	filestat;

	if ((fd = open(av[1], O_RDWR)) != 1)
	{
		if (fstat(fd, &filestat) == -1)
			return (1);
		buf = (char *)malloc(sizeof(char) * filestat.st_size);
		read(fd, buf, filestat.st_size);
		len = ft_itoa(filestat.st_size);
		send(sock, len, ft_strlen(len) + 1, 0);
		ft_strdel(&len);
		send(sock, "\r\n", 2, 0);
		send(sock, buf, filestat.st_size, 0);
		ft_strdel(&buf);
	}
	close(fd);
	return (0);
}

static int	ftp_builtin_put_cut(int sock)
{
	char	msg[3];
	char	*file;

	read(sock, msg, 3);
	if (ft_strcmp(msg, "fl") == 0)
	{
		while (42)
		{
			write(1, "File already exists, replace it?(y/n)\n", 37);
			if (get_next_line(1, &file) != 1)
				return (0);
			if (ft_tolower(file[0]) == 'y')
			{
				ft_strdel(&file), write(sock, "y\0", 2);
				break ;
			}
			else if (ft_tolower(file[0]) == 'n')
			{
				write(sock, file, 2), ft_strdel(&file);
				return (0);
			}
			ft_strdel(&file);
		}
	}
	return (1);
}

void		ftp_builtin_put(char **av, int sock)
{
	char	*full_cmd;
	char	*cmd;

	if (av[1] && !(ftp_acess(av[1])))
	{
		cmd = ft_strdup(av[1]);
		full_cmd = ft_strjoin("STOR ", cmd);
		write(sock, full_cmd, ft_strlen(full_cmd) + 1);
		ft_strdel(&cmd);
		ft_strdel(&full_cmd);
	}
	else
	{
		ft_putendl("ERROR: Can't send this file");
		return ;
	}
	if (ftp_builtin_put_cut(sock))
	{
		if (ftp_builtin_put_send(sock, av))
			ft_putendl_fd("ERROR: Unexpected error occured", 2);
		else
			ft_putendl("SUCCESS: Data successfully sent");
	}
	else
		ft_putendl_fd("ERROR: File not sent", 2);
}
