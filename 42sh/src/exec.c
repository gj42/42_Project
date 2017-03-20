/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 22:07:51 by bciss             #+#    #+#             */
/*   Updated: 2016/05/31 21:58:45 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

char	**g_env;

void	ft_execution(char *com, char **tb)
{
	pid_t	father;
	int		status;

	father = fork();
	save_cpid(&father);
	if (father != -1)
	{
		if (father == 0)
		{
			if (execve(com, tb, g_new_env ? g_new_env : g_env) == -1)
			{
				ft_putstr_fd("Format error:", 2);
				ft_putendl_fd(com, 2);
			}
			exit(0);
		}
		else
			waitpid(father, &status, 0);
	}
	if (WIFSIGNALED(status))
		sh_wrong_exit(WTERMSIG(status), com);
	sh_builtin_setenv_mng("_", com, &g_env);
	g_status = (status == 0) ? 1 : 0;
	father = 0;
	save_cpid(&father);
}

int		ft_exec(char *path, char *d_name, char **av2)
{
	char	buff[2048];

	ft_bzero(buff, 2048);
	ft_strcpy(buff, path);
	ft_strcat(buff, "/");
	ft_strcat(buff, d_name);
	ft_execution(buff, av2);
	return (1);
}

int		ft_isregular(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (0);
	if (S_ISREG(buf.st_mode))
		return (1);
	return (0);
}

int		ft_n_out_access(char **av2)
{
	if (access(av2[0], X_OK) != -1 && ft_isregular(av2[0]))
	{
		ft_execution(av2[0], av2);
		return (1);
	}
	return (0);
}

int		ft_check_exe(char **parsed, char *path_val)
{
	char			**path;
	struct dirent	*d;
	DIR				*dir;
	int				o;
	int				i;

	i = -1;
	o = 0;
	if (ft_n_out_access(parsed))
		return (1);
	if (path_val == NULL)
		return (0);
	path = ft_strsplit(path_val, ':');
	if (parsed[0] == NULL)
		return (0);
	while (path[++i] && !o)
		if ((dir = opendir(path[i])))
		{
			while ((d = readdir(dir)))
				if (!ft_strcmp(d->d_name, parsed[0]))
					o = ft_exec(path[i], d->d_name, parsed);
			closedir(dir);
		}
	(path) ? ft_arrfree(&path) : (path = NULL);
	return (o);
}
