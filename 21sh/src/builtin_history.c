/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:25:24 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/03 12:09:42 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <ctype.h>

int				ft_history(char **tb)
{
	t_hist		*ptr;

	(void)tb;
	ptr = g_history;
	while (ptr)
	{
		ft_putstr(ptr->str);
		ptr = ptr->next;
	}
	return (0);
}

int				builtin_history(char **buffer)
{
	get_line(g_history_string, g_history_file, ft_atoi(buffer[0] + 1));
	return (0);
}
