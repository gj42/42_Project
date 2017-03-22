/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_dataservcmd2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 18:07:13 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 16:33:12 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	ftp_getcmd_send(int cs, char *str)
{
	char	*buf;
	char	*len;
	t_stat	filestat;
	int		fd;
	char	file[2];

	if ((fd = open(str, O_RDWR)) != 1)
	{
		if (fstat(fd, &filestat) == -1)
			return ;
		buf = (char *)malloc(sizeof(char) * filestat.st_size);
		read(fd, buf, filestat.st_size);
		if (read(cs, file, 1))
		{
			file[1] = 0;
			if (file[0] == 'y')
			{
				len = ft_itoa(filestat.st_size);
				send(cs, len, ft_strlen(len) + 1, 0);
				send(cs, "\r\n", 2, 0);
				send(cs, buf, filestat.st_size, 0), ft_strdel(&len);
			}
		}
		close(fd), ft_strdel(&buf);
	}
}

void		ftp_getcmd(int cs, char *line)
{
	char	**cmd;

	cmd = ft_strsplit(line, ' ');
	if (!ftp_acess(cmd[1]))
	{
		write(cs, "ok\0", 3);
		ftp_getcmd_send(cs, cmd[1]);
	}
	else
		write(cs, "nf\0", 3);
	ft_arrfree(&cmd);
}
