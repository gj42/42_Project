/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localmanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 22:23:10 by bciss             #+#    #+#             */
/*   Updated: 2016/05/13 00:15:59 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		sh_get_local_pos(char *find, char **env)
{
	int i;

	i = 0;
	if (!env)
		return (-1);
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*sh_get_local(char *find, char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(find, env[i], ft_strchr(env[i], '=') - env[i]) == 0)
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
