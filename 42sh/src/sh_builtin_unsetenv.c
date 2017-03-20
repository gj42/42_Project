/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:39:04 by bciss             #+#    #+#             */
/*   Updated: 2016/05/07 00:52:08 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	sh_unsetenv_usage(void)
{
	ft_putstr_fd("unsetenv: usage: unsetenv [name]\n", 2);
}

static void	sh_builtin_delete(int n, char **av, char ***env)
{
	char	**new_env;
	int		i;

	i = 0;
	if ((new_env = (char**)malloc(sizeof(char*) * ft_arrlen(*env))) == NULL)
		return ;
	if (((n = sh_get_env_pos(av[1], *env)) >= 0) && (*env)[n])
	{
		while ((*env)[i] && i < n)
		{
			new_env[i] = (*env)[i];
			i++;
		}
		free((*env)[i]);
		while ((*env)[i] && ((*env)[i] = (*env)[i + 1]))
		{
			new_env[i] = (*env)[i];
			i++;
		}
		new_env[i] = NULL;
		free(*env);
		*env = new_env;
	}
}

int			sh_builtin_unsetenv(char **av)
{
	int		i;
	int		n;

	if (!av || !g_env)
		return (1);
	if (ft_arrlen(av) != 2)
	{
		sh_unsetenv_usage();
		return (1);
	}
	i = -1;
	n = 0;
	while ((g_env)[++i])
		if (sh_get_env_pos(av[1], g_env) >= 0)
			n++;
	if (n != 0)
		sh_builtin_delete(0, av, &g_env);
	else
	{
		ft_putendl_fd("unsetenv: wrong arg", 2);
		return (1);
	}
	return (0);
}
