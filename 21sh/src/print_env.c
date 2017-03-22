/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 01:54:34 by gjensen           #+#    #+#             */
/*   Updated: 2016/03/08 01:31:02 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh.h"

char	**g_env;

int		print_env(char *str)
{
	char	**tmp;

	if (ft_strcmp("env", str))
		return (0);
	tmp = g_env;
	while (*tmp)
		ft_putendl(*tmp++);
	ft_setenv("_", "env");
	return (1);
}
