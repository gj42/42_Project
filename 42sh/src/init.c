/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:04:44 by bciss             #+#    #+#             */
/*   Updated: 2016/05/18 16:13:58 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"
#include <stdlib.h>

static void	init_local(void)
{
	g_status = 0;
	if ((g_local = ft_dblstrnew(ENV_SIZE)) == NULL)
	{
		ft_putstr_fd(ERR_ALLOC_ENV, 2);
		denit();
	}
	g_local[0] = NULL;
}

static void	init_env(char **env, char *name)
{
	char	**tmp;
	char	*str;
	char	*new_lvl;

	if ((g_env = ft_dblstrnew(ENV_SIZE)) == NULL)
	{
		ft_putstr_fd(ERR_ALLOC_ENV, 2);
		denit();
	}
	tmp = g_env;
	while (env && *env)
		*tmp++ = ft_strdup(*env++);
	*tmp = NULL;
	if ((str = get_val("SHLVL")) == NULL)
		sh_builtin_setenv_mng("SHLVL", "1", &g_env);
	else
	{
		new_lvl = ft_itoa(ft_atoi(str) + 1);
		sh_builtin_setenv_mng("SHLVL", new_lvl, &g_env);
		ft_strdel(&new_lvl);
	}
	sh_builtin_setenv_mng("SHELL", name, &g_env);
	init_local();
}

static void	create_history(void)
{
	int		fd;

	fd = open(g_history_file, O_RDONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("42sh"": Path to create history not valid: ", 2);
		ft_putendl_fd(g_history_file, 2);
	}
}

void		set_history_file(void)
{
	char	*tmp;

	tmp = NULL;
	getcwd(tmp, MAXPATHLEN);
	ft_strlcat(g_history_file, tmp, MAXPATHLEN);
	ft_strlcat(g_history_file, "/history.txt", MAXPATHLEN);
	ft_strdel(&tmp);
	return ;
}

int			init(char **av, char **env)
{
	char	*buff[2];
	char	*tmp;
	char	*home;

	home = sh_get_env("HOME", env);
	init_env(env, av[0] + 2);
	if (!sh_get_env("TERM", g_env))
		ft_putendl_fd(ER, 2);
	if (home)
	{
		tmp = ft_strjoin(home, "/history.txt");
		ft_strlcat(g_history_file, tmp, MAXPATHLEN);
		ft_strdel(&tmp);
		if (!g_history_file[0])
			set_history_file();
		ft_init_history();
		buff[0] = "";
		buff[1] = ft_strjoin(home, "/.shrc");
		ft_config(buff);
		ft_strdel(&buff[1]);
		create_history();
	}
	else
		ft_putendl_fd("42sh"": Shell config not available, HOME not set", 2);
	return (0);
}
