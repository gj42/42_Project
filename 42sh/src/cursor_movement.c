/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:13:52 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 21:47:16 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					move_cursor_up(int cursor, char *to_edit)
{
	int x;
	int	y;
	int	len;
	int	width;

	width = get_col_term();
	len = ft_strlen_cur(to_edit, width, cursor);
	x = len % width;
	y = len / width;
	if (!y)
		return (cursor);
	cursor -= width;
	if (cursor < 0)
		cursor = 0;
	return (cursor);
}

int					move_cursor_down(int cursor, char *to_edit)
{
	int x;
	int	y;
	int	len;
	int	width;

	width = get_col_term();
	len = ft_strlen_cur(to_edit, width, cursor);
	x = len % width;
	y = len / width;
	if (y && !x)
	{
		--y;
		x = width;
	}
	if (y == (ft_strlen_term(to_edit, width) / width))
		return (cursor);
	cursor += width;
	return (cursor);
}

int					move_cursor_x(int cursor, char *to_edit)
{
	int		nb;
	int		width;

	width = get_col_term();
	nb = ft_strlen(to_edit);
	if (cursor <= 0)
		return (0);
	else if (cursor >= nb)
		return (nb);
	return (cursor);
}

int					cursor_movement(int key, int cursor, char *to_edit)
{
	int				move;

	move = 0;
	if (key == LEFT && cursor >= PROMPT_LEN - 1)
		cursor = cursor - 1;
	else if (key == RIGHT)
		cursor = cursor + 1;
	else if (key == END || key == CTRL_E)
		cursor = ft_strlen(to_edit);
	else if (key == HOME || key == CTRL_A)
		cursor = 0;
	else if (key == SHIFT_RIGHT)
	{
		move = size_until_next_word(to_edit, cursor);
		while (--move > 0)
			cursor++;
	}
	else if (key == SHIFT_LEFT)
		cursor = size_until_prev_word(to_edit, cursor);
	else if (key == PAGE_UP)
		cursor = move_cursor_up(cursor, to_edit);
	else if (key == PAGE_DOWN)
		cursor = move_cursor_down(cursor, to_edit);
	return (cursor);
}
