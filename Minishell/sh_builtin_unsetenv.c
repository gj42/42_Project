/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:39:04 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/11 18:34:14 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

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
			new_env[i] = (*env)[i], i++;
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

void		sh_builtin_unsetenv(char **av, char ***env)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!av || !env)
		return ;
	if (ft_arrlen(av) != 2)
	{
		sh_unsetenv_usage();
		return ;
	}
	while ((*env)[i])
	{
		if (sh_get_env_pos(av[1], *env) >= 0)
			n++;
		i++;
	}
	if (n != 0)
		sh_builtin_delete(0, av, env);
	else
		ft_putendl_fd("unsetenv: wrong arg", 2);
}
