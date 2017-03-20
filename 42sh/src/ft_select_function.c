/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:52:30 by bciss             #+#    #+#             */
/*   Updated: 2016/03/14 17:54:52 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void				choose(t_select *list)
{
	if (list->atm == 1)
	{
		if (list->choosed == 1)
			list->choosed = 0;
		else
		{
			list->choosed = 1;
			list->finish = 1;
		}
	}
}

void				c_left(t_select *list)
{
	size_t	tmp;

	tmp = 0;
	while (tmp++ < list->size + 1)
		tputs(tgetstr("le", NULL), 1, t_puts);
	list->atm = 0;
	list->prev->atm = 1;
}

void				c_right(t_select *list)
{
	size_t	tmp;

	tmp = 0;
	while (tmp++ < list->size + 1)
		tputs(tgetstr("le", NULL), 1, t_puts);
	list->atm = 0;
	list->next->atm = 1;
}

static	t_select	*get_ptr_atm(t_select *list)
{
	while (list->atm != 1)
		list = list->next;
	return (list);
}

char				*do_select(t_select *list)
{
	t_select		*tmp;

	if ((tputs(tgetstr("vi", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	tmp = list;
	while (42)
	{
		do_refresh(tmp);
		list = get_ptr_atm(list);
		key_wait(list);
		if (list->finish == 1)
			break ;
	}
	return (get_choosen_word(tmp));
}
