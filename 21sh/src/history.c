/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:18:54 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/11 23:28:30 by gjensen          ###   ########.fr       */
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

char					*history_navigation(char *file, int key, char *str)
{
	static int			line = -1;
	int					nb;

	(void)file;
	nb = count_lines_file(g_history_file);
	if (line == -1)
		line = nb + 1;
	if (key == DOWN)
	{
		if (line + 1 > nb)
			line = nb;
		else
			line += 1;
		str = ft_get_line_history(str, line);
	}
	else if (key == UP)
	{
		if (line - 1 <= 0)
			line = 0;
		else
			line -= 1;
		str = ft_get_line_history(str, line);
	}
	return (ft_trim_bs(str));
}
