/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:09:44 by bciss             #+#    #+#             */
/*   Updated: 2016/04/21 19:29:19 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		sh_builtin_exit(char **av)
{
	unsigned char	val;

	val = 0;
	if (av && av[1])
	{
		if (ft_isdigit(av[1][0]))
			val = ft_atoi(av[1]);
		else
		{
			ft_putendl_fd("exit: Expression Syntax.", 2);
			return (0);
		}
	}
	free_env();
	exit(val);
	return (1);
}
