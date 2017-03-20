/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:50:26 by bciss             #+#    #+#             */
/*   Updated: 2016/05/15 20:42:33 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <sys/stat.h>

int		sh_statpath(char *path)
{
	int			state;
	struct stat	filestat;

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

char	*sh_replace_home(char *path, char **env, int ret)
{
	char *home_path;
	char *pos;
	char *new_path;

	new_path = ft_strdup(path);
	home_path = sh_get_env("HOME", env);
	if ((pos = ft_strstr(path, home_path)) && ft_strcmp("/", home_path) != 0)
	{
		new_path[0] = '~';
		new_path[1] = 0;
		ft_strcat(new_path, pos + ft_strlen(home_path));
	}
	ft_putstr(new_path);
	if (ret)
		ft_putchar('\n');
	ft_strdel(&new_path);
	return (path);
}

int		sh_get_env_pos(char *find, char **env)
{
	int i;

	i = 0;
	if (!env)
		return (-1);
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*sh_get_env(char *find, char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	**sh_parse_env(char *find, char **env)
{
	char	**array_path;
	char	*path;

	if (!env)
		return (NULL);
	if ((path = sh_get_env(find, env)) == NULL)
		return (NULL);
	array_path = ft_strsplit(path, ':');
	return (array_path);
}
