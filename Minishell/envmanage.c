/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envmanage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:50:26 by gjensen           #+#    #+#             */
/*   Updated: 2015/06/11 18:19:12 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**sh_save_env(char ***env)
{
	static char	**save;

	if (env && *env)
	{
		save = *env;
		return (NULL);
	}
	else
		return (save);
}

char	*sh_replace_home(char *path, char **env)
{
	char *home_path;
	char *pos;

	home_path = sh_get_env("HOME", env);
	if ((pos = ft_strstr(path, home_path)) && ft_strcmp("/", home_path) != 0)
	{
		path[0] = '~';
		path[1] = 0;
		ft_strcat(path, pos + ft_strlen(home_path));
	}
	return (path);
}

int		sh_get_env_pos(char *find, char **env)
{
	int i;

	i = 0;
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

	if ((path = sh_get_env(find, env)) == NULL)
		return (NULL);
	array_path = ft_strsplit(path, ':');
	return (array_path);
}
