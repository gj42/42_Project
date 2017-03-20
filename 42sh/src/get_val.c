/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 02:17:17 by bciss             #+#    #+#             */
/*   Updated: 2016/04/28 19:02:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**g_env;

char	*get_val(char *var)
{
	char	**head;
	char	*cur;
	size_t	len;

	if (!g_env)
		return (NULL);
	len = ft_strlen(var);
	head = g_env;
	while (*g_env)
	{
		if (ft_strnequ(*g_env, var, len) && ((*g_env)[len] == '='))
		{
			cur = *g_env;
			g_env = head;
			return (cur + len + 1);
		}
		(void)*g_env++;
	}
	g_env = head;
	return (NULL);
}
