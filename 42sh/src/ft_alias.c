/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 03:37:17 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 05:31:11 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_del_unalias(int i)
{
	if (g_alias[i])
	{
		while (g_alias[i + 1])
		{
			ft_strdel(&g_alias[i]);
			g_alias[i] = ft_strdup(g_alias[i + 1]);
			i++;
		}
		ft_strdel(&g_alias[i]);
		return (1);
	}
	else
		return (0);
}

int		ft_check_unalias(char **str)
{
	char	**split;
	int		i;

	i = 0;
	while (g_alias[i])
	{
		split = ft_strsplit(g_alias[i], '=');
		if (ft_strnequ(g_alias[i], str[1], ft_strlen(split[0])) &&
ft_strnequ(g_alias[i], str[1], ft_strlen(str[1])))
		{
			ft_arrfree(&split);
			break ;
		}
		ft_arrfree(&split);
		i++;
	}
	if (!ft_del_unalias(i))
		ft_putendl("No Alias found!");
	return (1);
}

int		ft_unalias(char **str)
{
	int		i;

	i = 0;
	if (str && str[0] && !str[1])
	{
		ft_putendl_fd("sh: unalias usage: unalias <aliasName>", 2);
	}
	else
	{
		if (g_alias[i])
			ft_check_unalias(str);
		else
			ft_putendl("No Alias set");
	}
	return (1);
}

char	*ft_match_alias(char *str)
{
	int		i;
	char	**split;

	i = 0;
	while (g_alias && g_alias[i])
	{
		split = ft_strsplit(g_alias[i], '=');
		if (ft_strequ(split[0], str))
		{
			if (str && split[1])
				ft_strdel(&str);
			if (split[1])
				str = ft_strdup(split[1]);
		}
		ft_arrfree(&split);
		i++;
	}
	return (str);
}

char	*ft_calias(char *str)
{
	char	**split;
	char	buff[0xf000];
	int		i;

	i = 0;
	buff[i] = '\0';
	if ((split = ft_smartsplit(str, ' ')))
	{
		split[i] = ft_match_alias(split[0]);
	}
	while (split[i])
	{
		ft_strlcat(buff, split[i++], 0xf000);
		if (split[i])
			ft_strlcat(buff, " ", 0xf000);
	}
	str = ft_strdup(buff);
	ft_arrfree(&split);
	return (str);
}
