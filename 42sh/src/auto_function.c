/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:27:20 by bciss             #+#    #+#             */
/*   Updated: 2016/05/16 11:02:14 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					get_tab_size(char *path, char *str)
{
	struct dirent	*rd;
	DIR				*rep;
	int				i;
	int				nb;

	i = 0;
	nb = ft_strlen(str);
	if (!(rep = opendir(path)))
		ft_exit("Opendir failed");
	while ((rd = readdir(rep)))
		if (!(ft_strncmp(str, rd->d_name, nb)))
			i++;
	closedir(rep);
	return (i + 1);
}

int					get_path_size(const char *path)
{
	int				i;
	int				size;

	i = -1;
	size = 0;
	while (path[++i])
		if (path[i] == ':')
			size++;
	return (size);
}

char				*auto_complete(char *to_edit, int *cursor)
{
	char			**tb;
	char			*tmp;
	int				nb;

	tb = NULL;
	tmp = NULL;
	if (!to_edit[0] || (!ft_strcmp(to_edit, " \0")))
		return (to_edit);
	if (!(to_edit = prepare_autocomp(to_edit)))
		return (to_edit);
	*cursor = set_cursor(*cursor, to_edit);
	if ((nb = binary_launch(*cursor, to_edit)) >= 0)
		tmp = complete_binary(tb, to_edit, nb);
	else if (get_nb_word(to_edit) == 1)
		tmp = complete_command(to_edit, *cursor);
	else if (get_nb_word(to_edit) == 2)
		tmp = complete_other(tb, to_edit);
	else
		;
	to_edit = ft_strcpy(to_edit, tmp);
	*cursor = set_cursor(*cursor, to_edit);
	ft_strdel(&tmp);
	ft_refresh(to_edit, *cursor);
	return (to_edit);
}
