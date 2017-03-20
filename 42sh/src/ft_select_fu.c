/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_fu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 16:06:18 by bciss             #+#    #+#             */
/*   Updated: 2016/05/08 22:04:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				c_up(t_select *list)
{
	int				nb;

	nb = g_size;
	while (nb-- >= 0)
	{
		if (list->begin == 1)
		{
			c_left(list);
			list = list->prev;
		}
		c_left(list);
		list = list->prev;
	}
}

void				c_down(t_select *list)
{
	int				nb;

	nb = g_size;
	while (nb-- >= 0)
	{
		if (list->next->begin == 1)
		{
			c_right(list);
			list = list->next;
		}
		c_right(list);
		list = list->next;
	}
}
