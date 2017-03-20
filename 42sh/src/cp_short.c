/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:38:00 by bciss             #+#    #+#             */
/*   Updated: 2016/05/13 19:40:06 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*complete_command(char *to_edit, int cursor)
{
	char	*tmp;
	char	*path;
	int		i;

	i = -1;
	path = sh_get_env("PATH", g_env);
	tmp = autocomp_command(to_edit, path, i);
	ft_strcpy(to_edit, tmp);
	cursor += 1;
	return (to_edit);
}

char		*complete_binary(char **tb, char *to_edit, int nb)
{
	char	*buf;

	if (!(tb = find_local_binaries(".")))
		return (to_edit);
	if (!tb[0])
		return (to_edit);
	(void)nb;
	if (!tb[1])
	{
		ft_strcpy(to_edit, "./");
		ft_strlcat(to_edit, tb[0], 0xf000);
		ft_strlcat(to_edit, " ", 0xf000);
	}
	else
	{
		buf = ft_select(tb);
		ft_strlcat(to_edit, buf, 0xf000);
		ft_strlcat(to_edit, " ", 0xf000);
	}
	return (to_edit);
}

char		*complete_other(char **tb, char *to_edit)
{
	char	*buf;
	char	*word;

	if (to_edit[0] == ' ' && !to_edit[1])
		return (ft_strcpy(to_edit, " "));
	if (!(tb = get_autocomp_path(ft_strdup(to_edit))))
		return (to_edit);
	else if (!tb[1])
		return (to_edit);
	else
	{
		if ((!(word = autocomp_word(tb[2], tb[1]))) ||
				((ft_strncmp(word, to_edit, ft_strlen(to_edit) - 1)) == 0) ||
				(!(buf = ac_missing_chars(tb[2], ft_strlen(tb[2]), word))))
			return (to_edit);
		else
		{
			ft_strlcat(to_edit, buf, 0xf000);
			if (to_edit[ft_strlen(to_edit) - 1] != '/')
				ft_strlcat(to_edit, "/", 0xf000);
			else
				ft_strlcat(to_edit, " ", 0xf000);
		}
	}
	return (to_edit);
}

char		*prepare_autocomp(char *ptr)
{
	int		nb;

	nb = 0;
	if (!ptr[0])
		return (NULL);
	else
	{
		ptr = ft_strtrim(ptr);
		nb = ft_strlen(ptr);
		if (ptr[nb - 2] == '/' && ptr[nb - 1] == ' ')
			return (NULL);
	}
	return (ptr);
}
