/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:59:46 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/08 19:36:05 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char			*g_tb[11] =
{
	"echo", "env", "exit", "cd", "setenv", "unsetenv",
	"alias", "unalias", "source", "history", NULL
};

int				(*g_listefonctions[10])(char **) =
{
	ft_echo, sh_builtin_env, sh_builtin_exit, ft_cd,
	sh_builtin_setenv, sh_builtin_unsetenv, ft_alias,
	ft_unalias, ft_config, ft_history
};

static int		ft_check_builtin(char **av)
{
	int		i;

	i = 0;
	while (g_tb[i])
	{
		if (!ft_strcmp(av[0], g_tb[i]))
			return (i);
		i++;
	}
	return (-1);
}

int				ft_not_found(char ***parsed, char **str)
{
	g_status = 0;
	ft_putstr_fd("21sh"": Command not found: ", 2);
	ft_putendl_fd(*parsed[0], 2);
	ft_strdel(str);
	ft_arrfree(parsed);
	return (0);
}

int				ft_traitement(char *str)
{
	int		i;
	char	*path;
	char	**parsed;

	str = ft_formatting(str);
	i = ft_opera_handler(str);
	if (i >= 0)
	{
		ft_strdel(&str);
		return (i);
	}
	if (!(parsed = parse_command(str)))
	{
		ft_strdel(&str);
		return (-1);
	}
	i = ft_check_builtin(parsed);
	path = get_val("PATH");
	if (i >= 0)
		g_status = g_listefonctions[i](parsed);
	else if (!ft_check_exe(parsed, path))
		return (ft_not_found(&parsed, &str));
	ft_arrfree(&parsed);
	ft_strdel(&str);
	return (1);
}
