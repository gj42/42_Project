/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:04:31 by bciss             #+#    #+#             */
/*   Updated: 2016/04/21 22:31:22 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			free_the_shit(t_select **list)
{
	t_select	*tmp;
	t_select	*tt;

	while ((*list))
	{
		if ((*list)->index == 0)
			break ;
		(*list) = (*list)->next;
	}
	if ((*list))
	{
		tmp = (*list)->next;
		free(*list);
		while (tmp)
		{
			if (tmp == *list)
				break ;
			tt = tmp;
			tmp = tmp->next;
			free(tt);
		}
	}
}
