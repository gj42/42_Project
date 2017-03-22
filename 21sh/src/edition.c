/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:58:37 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/12 15:10:19 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*micro_prompt(void)
{
	static char		pline[0xf000];
	char			*ptr;

	write(1, "\n\n", 1);
	ft_bzero(pline, 0xf000);
	ptr = pline;
	minimal_prompt();
	while (ptr[ft_strlen(ptr) - 1] != '\n')
		ft_strlcpy(ptr, edit_slim(ptr), 0xf000);
	ptr = ft_strdup(pline);
	return (ptr);
}

char				*niark2(char *to_edit, int cursor)
{
	int		ret;
	char	*tmp;

	while ((ret = ft_check_key_words(to_edit)) == -1)
	{
		ft_putstr_cursor(to_edit, cursor);
		tmp = micro_prompt();
		ft_strlcat(to_edit, tmp, 0xf000);
		ft_strdel(&tmp);
	}
	if (ret == -2)
		ft_bzero(to_edit, 0xf000);
	return (ft_return(to_edit));
}

char				*line_edition(char *to_edit, int key)
{
	static	int		cursor = 0;

	ft_refresh(to_edit, cursor);
	cursor = set_cursor(cursor, to_edit);
	if (movement_key(key) == 1)
		cursor = cursor_movement(key, cursor, to_edit);
	else if (history_key(key) == 1)
	{
		to_edit = history_navigation(g_history_file, key, to_edit);
		cursor = ft_strlen(to_edit);
	}
	else if (key == RETURN)
		return (niark2(to_edit, cursor));
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

char				*ft_return(char *to_edit)
{
	char	*tmp;
	char	*ptr;

	minimal_prompt();
	ft_putstr(to_edit);
	tmp = to_edit;
	ptr = ft_strtrim(tmp);
	ft_strcpy(to_edit, ptr);
	ft_strdel(&ptr);
	ft_strlcat(to_edit, "\n", 0xf000);
	ptr = ft_strdup(to_edit);
	if (to_edit[0] != '\n' && to_edit[0])
		ft_add_history(ptr);
	ft_strdel(&ptr);
	write(1, "\n", 1);
	return (to_edit);
}

char				*ft_edit_and_history(char *str)
{
	int					key;
	struct termios		term;
	static	int			col = 0;
	static	int			line = 0;

	key = 0;
	get_term_size(&col, &line);
	if (!getenv("TERM"))
		return (NULL);
	term = set_term_canon();
	read(0, &key, sizeof(int));
	if (key == 4 || ft_strlen(str) > 0xefff)
	{
		unset_term_canon(term, str, NULL);
		exit(1);
	}
	str = line_edition(str, key);
	unset_term_canon(term, str, NULL);
	return (str);
}
