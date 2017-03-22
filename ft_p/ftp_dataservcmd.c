/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_dataservcmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 21:34:58 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/22 16:28:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	ftp_putcmd_recdata(int cs, int fd, int eol, int cr)
{
	char	buf[2];
	char	*len;
	int		ilen;
	char	*data;

	len = ft_strdup("");
	while (!eol)
	{
		if ((recv(cs, buf, 1, 0)) < 0)
			break ;
		buf[1] = 0;
		if (buf[0] == '\r')
			cr = 1;
		else if (cr == 1 && buf[0] == '\n')
			eol = 1;
		else if (cr && buf[0] != '\n')
			cr = 0;
		len = ft_strjoinfree(len, buf);
	}
	ilen = ft_atoi(len);
	data = (char *)malloc(sizeof(char) * (ilen));
	if ((recv(cs, data, ilen, 0)) == -1)
		return ;
	write(fd, data, ilen);
	ft_strdel(&len), ft_strdel(&data), close(fd);
}

static void	ftp_putcmd_cut(int cs, char *src)
{
	int		fd;
	char	file[3];

	if ((fd = open(src, O_CREAT | O_RDWR | O_EXCL, S_IRUSR
					| S_IWUSR | S_IRGRP | S_IROTH)) < 0)
	{
		write(cs, "fl\0", 3);
		while ((read(cs, file, 2)) > 0)
		{
			file[1] = 0;
			if (ft_tolower(file[0]) == 'y')
			{
				if ((fd = open(src, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR
							| S_IWUSR | S_IRGRP | S_IROTH)) < 0)
					return ;
				break ;
			}
			else if (ft_tolower(file[0]) == 'n')
				return ;
		}
	}
	else
		write(cs, "nl\0", 3);
	ftp_putcmd_recdata(cs, fd, 0, 0);
}

void		ftp_putcmd(int cs, char *arrcmd)
{
	char	**cmd;
	char	**src;
	int		i;

	cmd = ft_strsplit(arrcmd, ' ');
	src = ft_strsplit(cmd[1], '/');
	i = ft_arrlen(src) - 1;
	ftp_putcmd_cut(cs, src[i]);
	ft_arrfree(&cmd), ft_arrfree(&src);
}
