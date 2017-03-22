/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_slim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 01:56:29 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/12 01:18:58 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*ft_edit(char *str, char *truc)
{
	int					key;
	struct termios		term;

	key = 0;
	term = set_term_canon();
	str = edit_slim2(str, truc);
	unset_term_canon(term, str, NULL);
	return (str);
}

char				*edit_slim(char *to_edit)
{
	int				key;
	static	int		cursor = -1;

	read(0, &key, sizeof(int));
	ft_refresh(to_edit, cursor);
	if ((!((cursor = set_cursor(cursor, to_edit))) || cursor) && key == RETURN)
		ft_strlcat(to_edit, "\n", 0xf000);
	if (key == RETURN)
		return (to_edit);
	else if (movement_key(key) == 1)
		cursor = cursor_movement(key, cursor, to_edit);
	else if (history_key(key) == 1)
	{
		to_edit = history_navigation(g_history_file, key, to_edit);
		cursor = ft_strlen(to_edit);
	}
	else if (edition_key(key) == 1)
		to_edit = edition_func(to_edit, &cursor, key);
	else if ((get_t(key) && (size_t)cursor <= ft_strlen(to_edit)))
	{
		to_edit = insert_char(to_edit, get_t(key), &cursor);
		cursor++;
	}
	ft_putstr_cursor(to_edit, cursor);
	return (to_edit);
}

char				*micro_prompt2(void)
{
	static char		pline[0xf000];
	char			*ptr;

	ft_bzero(pline, 0xf000);
	ptr = pline;
	minimal_prompt();
	while (ptr[ft_strlen(ptr) - 1] != '\n')
		ft_strcpy(ptr, edit_slim(ptr));
	ptr = ft_strdup(pline);
	return (ptr);
}

char				*niark3(char *to_edit, int *cursor, char *truc)
{
	char			*line;

	ft_strlcat(to_edit, "\n", 0xfff);
	ft_putstr_cursor(to_edit, *cursor);
	while (1)
	{
		line = micro_prompt2();
		if (!ft_strcmp(ft_strtrim(line), truc))
			break ;
		ft_putstr_cursor(line, *cursor);
		ft_strlcat(to_edit, line, 0xfff);
	}
	*cursor = -1;
	return (to_edit);
}

char				*edit_slim2(char *to_edit, char *truc)
{
	int				key;
	static	int		cursor = -1;

	key = 0;
	read(0, &key, sizeof(int));
	cursor = set_cursor(cursor, to_edit);
	ft_refresh(to_edit, cursor);
	if (key == RETURN)
		return (niark3(to_edit, &cursor, truc));
	else if (movement_key(key) == 1)
		cursor = cursor_movement(key, cursor, to_edit);
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
