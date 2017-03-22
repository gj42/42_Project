/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 21:47:23 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/15 15:52:51 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ftp_isbin(char *path)
{
	int		state;
	t_stat	filestat;

	state = 0;
	if (lstat(path, &filestat) == -1)
		state = 0;
	else if (S_ISDIR(filestat.st_mode))
		state = 1;
	else if (S_ISLNK(filestat.st_mode))
		state = 3;
	else if (S_ISREG(filestat.st_mode))
		state = 2;
	return (state);
}

void	ftp_cprompt(char *addr, int port)
{
	printf("[%s:%d]\n", addr, port);
	ft_putstr("ft_p $>");
}

int		ftp_acess(char *path)
{
	if (ftp_isbin(path) == 2)
	{
		if (access(path, R_OK) == 0)
			return (0);
		else
			return (-1);
	}
	return (-1);
}

char	*ftp_opt_ls(char *buf)
{
	char	**option;

	option = ft_strsplit(buf, ' ');
	if (option[1])
	{
		if (option[1][0] == '-')
		{
			if (ft_strchr(option[1], 'a'))
			{
				ft_arrfree(&option);
				return ("-la");
			}
		}
	}
	ft_arrfree(&option);
	return ("-l");
}
