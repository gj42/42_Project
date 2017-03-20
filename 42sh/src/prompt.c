/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 00:46:31 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 03:43:46 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>

static int	is_small(char *path)
{
	int	nbr;

	nbr = 0;
	while (*path)
	{
		if (*path == '/' && nbr == 1)
			return (0);
		else if (*path == '/')
		{
			while (*path == '/')
				(void)*path++;
			nbr++;
		}
		else
			(void)*path++;
	}
	return (1);
}

static int	small_path(char *path)
{
	while (*path && *path == '/')
		(void)*path++;
	while (!is_small(path))
	{
		while (*path && *path != '/')
			(void)*path++;
		while (*path == '/')
			(void)*path++;
	}
	ft_putstr_cr("\033[38;5;20m", path);
	return (ft_strlen(path) + 2);
}

static int	git_status(void)
{
	char	*ref;
	int		fd;
	int		len;

	ref = NULL;
	fd = open(".git/HEAD", O_RDONLY);
	if (fd < 0)
		return (0);
	get_next_line(fd, &ref);
	ft_putstr_bold(" (");
	ft_putstr_cr("\033[38;5;9m", ref + 16);
	ft_putstr_bold(")");
	tputs(tgetstr("me", NULL), 1, t_puts);
	len = (ft_strlen(ref + 16) + 2 + 3);
	if (ref)
		ft_strdel(&ref);
	close(fd);
	return (len);
}

int			check_null(char **path, char **tmp)
{
	if (*path == NULL)
	{
		minimal_prompt();
		return (2);
	}
	*tmp = *path;
	getcwd(*path, MAXPATHLEN);
	return (0);
}

int			prompt(void)
{
	char	*path;
	char	*tmp;
	int		len;

	ft_putchar('\n');
	path = (char *)malloc(sizeof(char) * MAXPATHLEN);
	if (check_null(&path, &tmp))
		return (2);
	if (path == NULL)
	{
		minimal_prompt();
		return (2);
	}
	else
	{
		len = 0;
		len += small_path(path) + git_status();
		ft_putchar('\n');
		tputs(tgetstr("sc", NULL), 1, t_puts);
		minimal_prompt();
		ft_strdel(&tmp);
		return (len + 2);
	}
	ft_strdel(&tmp);
	path = NULL;
}
