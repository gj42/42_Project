/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_builtin_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 21:02:00 by bciss             #+#    #+#             */
/*   Updated: 2016/05/13 00:39:35 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void		sh_builtin_local_use(void)
{
	ft_putendl_fd("env: usage: local", 2);
}

static void		sh_print_local(char **env)
{
	int i;

	i = 0;
	if (env)
		while (env[i])
		{
			ft_putendl(env[i]);
			i++;
		}
}

int				sh_builtin_local_err(char **av)
{
	if (!av)
		return (0);
	if (av[1])
	{
		sh_builtin_local_use();
		return (1);
	}
	return (-1);
}

int				sh_builtin_local(char **av)
{
	int		j;

	j = sh_builtin_local_err(av);
	if (j > -1)
		return (j);
	sh_print_local(g_local);
	return (1);
}
