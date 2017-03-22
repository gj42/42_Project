/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 01:48:27 by gjensen           #+#    #+#             */
/*   Updated: 2016/01/14 05:53:17 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_sh.h"
#include "libft.h"

char	**g_env;

char	**copy_env(void)
{
	char	**dst;
	char	**tmp;
	size_t	len;

	if ((len = env_length(g_env)) == 0)
		return (NULL);
	if ((dst = ft_dblstrnew(len + 1)) == NULL)
		return (NULL);
	tmp = dst;
	while (*g_env)
	{
		if ((*tmp = ft_strdup(*g_env++)) == NULL)
			return (NULL);
		(void)*tmp++;
	}
	*tmp = NULL;
	return (dst);
}
