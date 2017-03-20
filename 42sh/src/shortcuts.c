/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:17:14 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 21:48:53 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				movement_key(int key)
{
	if (key == LEFT || key == RIGHT || key == END || key == CTRL_E ||
	key == CTRL_A || key == HOME || key == SHIFT_RIGHT || key == SHIFT_LEFT ||
	key == PAGE_UP || key == PAGE_DOWN)
		return (1);
	else
		return (0);
}

int				history_key(int key)
{
	if (key == UP || key == DOWN)
		return (1);
	else
		return (0);
}

int				edition_key(int key)
{
	if (key == DELETE || key == DEL || key == TAB ||
		key == CTRL_L || key == CTRL_V)
		return (1);
	else
		return (0);
}

char			*edition_func(char *to_edit, int *cursor, int key)
{
	char		*tmp;

	if (key == DEL)
	{
		if (*cursor > 0)
			to_edit = l_delete(to_edit, (*cursor)--);
	}
	else if (key == DELETE)
	{
		if (to_edit[*cursor] || to_edit[*cursor + 1])
			to_edit = r_delete(to_edit, *cursor);
	}
	else if (key == CTRL_L)
		ft_clear_screen(to_edit, *cursor);
	else if (key == CTRL_V)
	{
		tmp = insert_str_index(to_edit, cursor, ft_paste());
		to_edit = ft_strcpy(to_edit, tmp);
		ft_strdel(&tmp);
	}
	else
		;
	*cursor = set_cursor(*cursor, to_edit);
	return (to_edit);
}

void			ft_exit(char *str)
{
	denit();
	tputs(tgetstr("vs", NULL), 1, t_puts);
	ft_putstr(str);
	exit(0);
}
