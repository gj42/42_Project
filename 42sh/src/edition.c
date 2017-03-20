/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:58:37 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 21:45:28 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char					*micro_prompt(void)
{
	static char			pline[0xf000];
	char				*ptr;

	ft_bzero(pline, 0xf000);
	ptr = pline;
	minimal_prompt();
	while (ptr[ft_strlen(ptr) - 1] != '\n')
		ft_strlcpy(ptr, edit_slim(ptr), 0xf000);
	ft_putstr_cursor(ptr, 0);
	ptr = ft_strdup(pline);
	return (ptr);
}

static char				*loop_quotes(char *to_edit, int cursor)
{
	int					ret;
	static int			flag;
	char				*tmp;

	cursor = 0;
	flag = 0;
	ft_putstr_cursor(to_edit, cursor);
	while ((ret = ft_check_key_words(to_edit)) == -1)
	{
		if (flag == 0)
			write(1, "\n", 1);
		flag = 1;
		tmp = micro_prompt();
		ft_strlcat(to_edit, tmp, 0xf000);
		ft_strdel(&tmp);
	}
	if (ret == -2)
		ft_bzero(to_edit, 0xf000);
	return (ft_return(to_edit));
}

char					*line_edition(char *to_edit, int key)
{
	static	int			cursor = 0;

	ft_refresh(to_edit, cursor);
	cursor = set_cursor(cursor, to_edit);
	if (movement_key(key) == 1)
		cursor = cursor_movement(key, cursor, to_edit);
	else if (history_key(key) == 1)
	{
		to_edit = history_navigation(key, to_edit);
		cursor = ft_strlen(to_edit);
	}
	else if (key == RETURN)
		return (loop_quotes(to_edit, cursor));
	else if (edition_key(key) == 1)
		to_edit = edition_func(to_edit, &cursor, key);
	else if ((get_t(key) && (size_t)cursor <= ft_strlen(to_edit)))
	{
		to_edit = insert_char(to_edit, get_t(key), &cursor);
		cursor += 1;
	}
	ft_putstr_cursor(to_edit, cursor);
	return (to_edit);
}

char					*ft_return(char *to_edit)
{
	char				*tmp;
	char				*ptr;

	tmp = to_edit;
	ptr = ft_strtrim(tmp);
	ft_strcpy(to_edit, ptr);
	ft_strdel(&ptr);
	ft_strlcat(to_edit, "\n", 0xf000);
	ptr = ft_strdupc(to_edit, '\n');
	if (ptr[0] != '\n' && ptr[0])
		ft_add_history(ptr);
	ft_strdel(&ptr);
	write(1, "\n", 1);
	return (to_edit);
}

char					*ft_edit_and_history(char *str)
{
	int					key;
	struct termios		term;
	static	int			col = 0;
	static	int			line = 0;

	key = 0;
	get_term_size(&col, &line);
	term = set_term_canon();
	if (!sh_get_env("TERM", g_env))
	{
		unset_term_canon(term, str);
		return (NULL);
	}
	read(0, &key, sizeof(int));
	if ((key == 4 && ft_strlen(str) == 0) || ft_strlen(str) > 0xefff)
	{
		unset_term_canon(term, str);
		exit(1);
	}
	str = line_edition(str, key);
	unset_term_canon(term, str);
	return (str);
}
