/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:23:34 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 22:17:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			set_cursor(int cursor, char *buffer)
{
	int		size;

	size = ft_strlen(buffer);
	if (cursor == -1)
	{
		if (size == 1)
			cursor = -1;
		else
			cursor = size - 1;
	}
	return (move_cursor_x(cursor, buffer));
}

int			refresh_cursor(int cursor, char *to_edit)
{
	int		nb;

	if ((nb = ft_strlen(to_edit)) == 0)
		return (0);
	(void)cursor;
	return (move_cursor_x(nb, to_edit));
}

void		ft_clear_screen(char *to_edit, int cursor)
{
	if ((tputs(tgetstr("cl", NULL), 1, t_puts)) == -1)
		ft_exit("Tputs error");
	prompt();
	ft_refresh(to_edit, cursor);
}

char		*l_delete(char *to_edit, int cursor)
{
	char	edited[0xf000];
	int		i;
	int		k;

	i = -1;
	while (to_edit[++i] && i < cursor - 1)
		edited[i] = to_edit[i];
	k = i - 1;
	while (to_edit[++i])
		edited[++k] = to_edit[i];
	edited[++k] = '\0';
	ft_strcpy(to_edit, edited);
	return (to_edit);
}

char		*r_delete(char *to_edit, int cursor)
{
	char	edited[0xf000];
	int		i;
	int		k;

	i = -1;
	if (to_edit[cursor + 1] == '\0' && to_edit[cursor] == ' ')
		return (to_edit);
	while (to_edit[++i] && i < cursor)
		edited[i] = to_edit[i];
	k = i;
	while (to_edit[i++])
		edited[k++] = to_edit[i];
	edited[k] = '\0';
	ft_strcpy(to_edit, edited);
	return (to_edit);
}
