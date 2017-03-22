/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:37:01 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/04 19:47:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <sys/param.h>
#include <unistd.h>

static void	check_error_cd(char *path)
{
	char	*str;

	if (!sh_statpath(path))
		str = ft_strjoin("21sh"": cd: no such file or directory: ", path);
	else if (access(path, R_OK) != 0 || access(path, W_OK) != 0)
		str = ft_strjoin("21sh"": cd: permission denied: ", path);
	else
		str = ft_strjoin("21sh"": cd: not a directory: ", path);
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
}

static void	change_var(char *path, char buf[MAXPATHLEN])
{
	if (buf != NULL)
		ft_setenv("OLDPWD", buf);
	if (getcwd(buf, MAXPATHLEN) != NULL)
		ft_setenv("PWD", buf);
	else
		ft_setenv("PWD", path);
}

static int	change_dir(char *path)
{
	char	buf[MAXPATHLEN];

	if (access(path, F_OK) == 0)
	{
		getcwd(buf, MAXPATHLEN);
		if (chdir(path) != 0)
			check_error_cd(path);
		else
		{
			change_var(path, buf);
			return (1);
		}
	}
	else
		check_error_cd(path);
	return (0);
}

int			ft_cd(char **path)
{
	char	*str;

	if (!path)
		return (0);
	if (ft_arrlen(path) > 2)
		ft_putendl_fd("21sh"": cd: too many arguments", 2);
	else if (path[1] && ft_strcmp(path[1], "-") == 0)
	{
		if ((str = get_val("OLDPWD")) != NULL)
			return (change_dir(str));
		else
			ft_putendl_fd("21sh"": cd: OLDPWD not set", 2);
	}
	else if (ft_arrlen(path) == 1)
	{
		if ((str = get_val("HOME")))
			return (change_dir(str));
		else
			ft_putendl_fd("21sh"": cd: HOME not set", 2);
	}
	else
		return (change_dir(path[1]));
	return (0);
}
