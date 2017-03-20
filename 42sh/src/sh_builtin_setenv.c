/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 17:31:03 by bciss             #+#    #+#             */
/*   Updated: 2016/05/16 11:34:57 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	sh_builtin_setenv_add(char *name, char *value, char ***env)
{
	char	**new_env;
	int		i;
	char	*new_str;

	i = 0;
	if ((new_env = (char**)malloc(sizeof(char*)
					* (ft_arrlen(*env) + 2))) == NULL)
		return ;
	while ((*env)[i])
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_str = ft_strjoin(name, "=");
	new_env[i] = ft_strjoin(new_str, value);
	new_env[++i] = NULL;
	ft_strdel(&new_str);
	free(*env);
	*env = new_env;
}

static void	sh_builtin_setenv_replace(char *name, char *value, char **env)
{
	int		pos;
	char	*new_env;
	char	*new_val;

	pos = sh_get_env_pos(name, env);
	new_env = ft_strjoin(name, "=");
	new_val = ft_strjoin(new_env, value);
	ft_strdel(&(env[pos]));
	env[pos] = new_val;
	ft_strdel(&new_env);
}

void		sh_builtin_setenv_mng(char *name, char *value, char ***env)
{
	if (!name || *name == 0 || ft_strchr(name, '=') != NULL ||
			!value || !env)
		return ;
	if (sh_get_env(name, *env))
		sh_builtin_setenv_replace(name, value, *env);
	else
		sh_builtin_setenv_add(name, value, env);
}

void		sh_builtin_setenv2(char **av, char ***env)
{
	char	**splitvar;
	int		i;

	i = 0;
	if (!av || !env)
		return ;
	while (av[i] && !ft_strchr(av[i], '='))
		i++;
	while (av[i] && ft_strchr(av[i], '='))
	{
		splitvar = ft_strsplit(av[i], '=');
		if (splitvar[1])
			sh_builtin_setenv_mng(splitvar[0], splitvar[1], env);
		else
			sh_builtin_setenv_mng(splitvar[0], "", env);
		i++;
		ft_arrfree(&splitvar);
	}
}

int			sh_builtin_setenv(char **av)
{
	if (!av)
		return (-1);
	if (g_env)
		sh_builtin_setenv2(av, &g_env);
	else
		return (-1);
	return (0);
}
