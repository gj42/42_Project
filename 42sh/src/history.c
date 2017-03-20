/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:18:54 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 22:18:08 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int						bs_count(char *to_edit)
{
	int					nb;
	int					i;

	i = -1;
	nb = 0;
	while (to_edit[++i])
	{
		if (to_edit[i] == '\n')
			nb++;
	}
	return (nb);
}

void					ft_refresh(char *to_edit, int cursor)
{
	int					x;
	int					y;
	int					len;
	int					width;

	tputs(tgetstr("vi", NULL), 1, t_puts);
	width = get_col_term();
	len = ft_strlen_cur(to_edit, width, cursor);
	if (width == 0)
		width = 1;
	x = len % width;
	y = len / width;
	if (y && !x)
	{
		--y;
		x = width;
	}
	while (y-- > 0)
		tputs(tgetstr("up", NULL), 1, t_puts);
	while (x-- > 0)
		tputs(tgetstr("le", NULL), 1, t_puts);
	tputs(tgetstr("cd", NULL), 1, t_puts);
}

char					*ft_trim_bs(char *to_edit)
{
	int					i;

	i = 0;
	if (!to_edit)
		return (NULL);
	while (to_edit[i] != '\n')
	{
		if (!to_edit[i])
			return (to_edit);
		i++;
	}
	to_edit[i] = '\0';
	return (to_edit);
}

char					*history_navigation(int key, char *str)
{
	static int			line = 0;
	static	char		buf[0xf000];
	int					nb;

	if (g_hist == 0)
	{
		line = 0;
		ft_strcpy(buf, str);
		g_hist = 1;
	}
	nb = count_lines_file(g_history_file) + 1;
	if (key == DOWN)
		str = history_buffer_check(str, buf, &line, nb);
	else if (key == UP)
	{
		if (line == 0)
		{
			ft_bzero(buf, 0xf000);
			ft_strcpy(buf, str);
		}
		if (line < nb - 1)
			line++;
		str = ft_get_line_history(str, nb - (line + 1));
	}
	return (ft_trim_bs(str));
}
