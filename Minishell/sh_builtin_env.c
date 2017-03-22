/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 16:43:20 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/28 18:09:08 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	sh_builtin_env_use(void)
{
	ft_putendl_fd("env: usage: [i] [name=value ...] [utility [arg ...]]", 2);
}

static void	sh_print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

static void	sh_builtin_env_exec(char **av, char ***new_env, int i)
{
	char	**array_path;
	char	*new_cmd;

	while (av[i] && ft_strchr(av[i], '='))
		i++;
	if (av[i])
	{
		new_cmd = ft_joinarray(&av[i]);
		array_path = sh_parse_env("PATH", *new_env);
		if (av[i])
			sh_execute_cmd(new_cmd, new_env, array_path);
		if (array_path)
			ft_arrfree(&array_path);
	}
	else
		sh_print_env(*new_env);
}

void		sh_builtin_env(char **av, char ***env)
{
	int		i;
	char	**new_env;
	int		arg_len;

	if (!av || !env || !(*av))
		return ;
	i = 1;
	if (av[1] && ft_strcmp(av[1], "-help") == 0)
		return (sh_builtin_env_use());
	if (av[1] && ft_strcmp(av[1], "-i") == 0)
	{
		i = 2;
		arg_len = ft_arrlen(av);
		if (!(new_env = (char**)malloc(sizeof(char *) * (arg_len + 1))))
			return ;
		new_env[0] = NULL;
		arg_len = 0;
	}
	else
		new_env = ft_arrcpy(*env);
	if (av[i] || ft_strchr(av[i], '='))
		sh_builtin_setenv(av, &new_env);
	sh_builtin_env_exec(av, &new_env, i);
	if (new_env)
		ft_arrfree(&new_env);
}
