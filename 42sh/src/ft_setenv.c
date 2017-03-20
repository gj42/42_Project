/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 10:07:12 by bciss             #+#    #+#             */
/*   Updated: 2016/04/28 19:22:13 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"
#include <stdlib.h>

char	**g_env;

static int	concate_var(char *name, char *val)
{
	char	**head;
	char	*str;

	if ((str = concate(name, val, "=")) == NULL)
		return (0);
	head = g_env;
	while (*g_env)
		(void)*g_env++;
	*g_env = str;
	(void)*g_env++;
	*g_env = NULL;
	g_env = head;
	return (1);
}

static int	replace_var(char *name, char *val)
{
	char	**head;
	char	*var;
	size_t	len;

	if ((var = concate(name, val, "=")) == NULL)
		return (0);
	head = g_env;
	len = ft_strlen(name);
	while (*g_env)
	{
		if (ft_strnequ(*g_env, name, len) && ((*g_env)[len] == '='))
		{
			free(*g_env);
			*g_env = var;
			g_env = head;
			return (1);
		}
		(void)*g_env++;
	}
	g_env = head;
	return (0);
}

int			ft_setenv(char *name, char *val)
{
	if (!is_var(name))
		return (concate_var(name, val));
	else
		return (replace_var(name, val));
}
