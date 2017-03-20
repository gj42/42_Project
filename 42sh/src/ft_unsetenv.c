/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:15:48 by bciss             #+#    #+#             */
/*   Updated: 2016/03/07 22:53:26 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sh.h"
#include "libft.h"

char	**g_env;

static void	swap_end(void)
{
	while (*g_env)
	{
		*g_env = *(g_env + 1);
		(void)*g_env++;
	}
}

void		ft_unsetenv(char *var)
{
	char	**head;
	size_t	len;

	len = ft_strlen(var);
	head = g_env;
	while (*g_env)
	{
		if (ft_strnequ(*g_env, var, len) && ((*g_env)[len] == '='))
		{
			swap_end();
			g_env = head;
			return ;
		}
		(void)*g_env++;
	}
	g_env = head;
}
