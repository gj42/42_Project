/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 02:54:45 by bciss             #+#    #+#             */
/*   Updated: 2016/05/09 17:21:19 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	previous_newline_cursor(char *buf, int cur)
{
	int	i;

	i = cur;
	while (i > 0 && buf[i] != '\n')
		i--;
	return (i);
}

int			get_cursor_below(char *buf, int cur)
{
	int	i;
	int	j;
	int	delta;

	if (cur < 0)
		return (-1);
	i = cur;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (i);
	delta = cur - previous_newline_cursor(buf, cur);
	j = 1;
	while (buf[i + j] && buf[i + j] != '\n' && j < delta)
		j++;
	return (i + j);
}

int			get_cursor_above(char *buf, int cur)
{
	int	i;
	int	j;
	int	delta;

	if (cur < 0)
		return (-1);
	i = previous_newline_cursor(buf, cur);
	if (i == 0)
		return (0);
	i--;
	while (i > 0 && buf[i] != '\n')
		i--;
	j = 1;
	delta = cur - previous_newline_cursor(buf, cur);
	while (buf[i + j] && buf[i + j] != '\n' && j < delta)
		j++;
	if (buf[i + j] == '\n')
		return (i + j - 1);
	return (i + j);
}

int			ft_strlen_b4n(char *str, int nb)
{
	int		size;

	size = -1;
	while (str[++size] && nb > 0)
		if (str[size] == '\n')
			nb--;
	return (size);
}

int			multiline(char *to_edit, int cursor, int bs)
{
	int				tmp;
	int				nb;

	cursor += 2;
	tmp = bs + 1;
	while (tmp-- >= 0)
		tputs(tgetstr("do", NULL), 1, t_puts);
	nb = 1;
	cursor += ft_strlen_b4n(to_edit, nb);
	nb++;
	return (cursor);
}
