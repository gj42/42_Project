/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:19:34 by bciss             #+#    #+#             */
/*   Updated: 2016/03/02 01:43:43 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**g_env;

size_t	is_var(char *var)
{
	char	**tmp;
	size_t	len;
	size_t	i;

	len = ft_strlen(var);
	if (len == 0)
		return (0);
	i = 0;
	tmp = g_env;
	while (*tmp)
	{
		if (ft_strnequ(*tmp, var, len) && ((*tmp)[len] == '='))
			i++;
		(void)*tmp++;
	}
	return (i);
}
