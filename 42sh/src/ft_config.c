/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 16:52:58 by bciss             #+#    #+#             */
/*   Updated: 2016/05/11 17:20:38 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "get_next_line.h"
#include "libft.h"

char	**g_alias;

int		ft_print_alias(void)
{
	int		i;

	i = 0;
	if (g_alias)
	{
		while (g_alias[i])
			ft_putendl(g_alias[i++]);
	}
	else
		ft_putendl("No Alias Set");
	return (1);
}

int		ft_check_alias(char **str)
{
	int		i;
	char	**split;
	char	**check;

	i = 0;
	check = ft_smartsplit(str[1], '=');
	while (g_alias && g_alias[i] && i < 1024)
	{
		split = ft_smartsplit(g_alias[i], '=');
		if (ft_strequ(split[0], check[0]))
		{
			ft_arrfree(&split);
			break ;
		}
		ft_arrfree(&split);
		i++;
	}
	ft_arrfree(&check);
	if (g_alias[i])
		ft_strdel(&g_alias[i]);
	g_alias[i] = ft_strdup(str[1]);
	return (i);
}

int		ft_verif_alias(char **str)
{
	char	**split;

	if (!ft_strchr(str[1], '='))
		return (0);
	if (!(split = ft_strsplit(str[1], '=')))
		return (0);
	ft_arrfree(&split);
	return (1);
}

int		ft_alias(char **str)
{
	int		i;

	i = 0;
	if (str[0] && !str[1])
	{
		ft_print_alias();
		return (1);
	}
	if (str[1] && !ft_verif_alias(str))
		return (0);
	if (g_alias && str[1])
		i = ft_check_alias(str);
	else if (i < ENV_SIZE && str[1])
	{
		if (!(g_alias = ft_dblstrnew(ENV_SIZE)))
			return (0);
		else
			g_alias[i] = ft_strdup(str[1]);
	}
	else if (i >= ENV_SIZE)
		ft_putendl("too Many Aliases");
	else
		ft_putendl("No argument");
	return (1);
}

int		ft_config(char **file)
{
	int		fd;
	char	*buff;
	char	*tmp;
	char	*path;

	if (!file || !file[1])
	{
		ft_putendl("usage: source <file>");
		return (0);
	}
	tmp = sh_get_env("HOME", g_env);
	path = ft_strjoin(tmp, "/.shrc");
	if ((fd = open(file[1], O_RDONLY, 0644)) < 0 && !ft_strequ(path, file[1]))
		return (alias_open_err(file[1], &path, fd));
	ft_strdel(&path);
	while (get_next_line(fd, &buff) > 0)
	{
		execute_command(buff);
		ft_strdel(&buff);
	}
	if (buff)
		ft_strdel(&buff);
	close(fd);
	return (1);
}
