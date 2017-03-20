/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 16:43:20 by bciss             #+#    #+#             */
/*   Updated: 2016/05/13 18:12:52 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		sh_builtin_env_use(void)
{
	ft_putendl_fd("env: usage: -[i] [name=value ...] [utility [arg ...]]", 2);
}

static void		sh_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

static void		sh_builtin_env_exec(char **av, char ***new_env, int i)
{
	char	*array_path;

	while (av[i] && ft_strchr(av[i], '='))
		i++;
	if (av[i])
	{
		array_path = sh_get_env("PATH", g_env);
		if (av[i])
			ft_check_exe(&av[i], array_path);
	}
	else
		sh_print_env(*new_env);
}

int				sh_builtin_env_err(char **av)
{
	if (!av || !(*av))
		return (0);
	if (av[1] && ft_strcmp(av[1], "-help") == 0)
	{
		sh_builtin_env_use();
		return (1);
	}
	return (-1);
}

int				sh_builtin_env(char **av)
{
	int		i;
	int		j;
	int		arg_len;

	j = sh_builtin_env_err(av);
	if (j > -1)
		return (j);
	i = 1;
	if (av[1] && ft_strcmp(av[1], "-i") == 0)
	{
		i = 2;
		arg_len = ft_arrlen(av);
		if (!(g_new_env = (char**)malloc(sizeof(char *) * (arg_len + 1))))
			return (0);
		g_new_env[0] = NULL;
	}
	else
		g_new_env = ft_arrcpy(g_env);
	if (av[i] && ft_strchr(av[i], '='))
		sh_builtin_setenv2(av, &g_new_env);
	sh_builtin_env_exec(av, &g_new_env, i);
	if (g_new_env)
		ft_arrfree(&g_new_env);
	ft_setenv("_", "env");
	return (1);
}
