/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:00:15 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 23:25:35 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		set_line(char *to_edit, int cursor)
{
	tputs(tgetstr("rc", NULL), 1, t_puts);
	minimal_prompt();
	ft_refresh(to_edit, cursor);
	return (cursor);
}

void	set_time(t_hist *histo)
{
	char	*tmp;

	tmp = ft_itoa(get_timestamp());
	ft_strlcat(histo->time, "[", 14);
	ft_strlcat(histo->time, tmp, 14);
	ft_strlcat(histo->time, "]:", 14);
	ft_strdel(&tmp);
}

int		alias_open_err(char *file, char **path, int fd)
{
	ft_putstr(file);
	ft_putendl(" not found");
	ft_strdel(path);
	close(fd);
	return (0);
}

int		check_adjacent_red(char *str, int i)
{
	if (str[i] == str[i - 1])
		i++;
	if (str[i] == '&')
	{
		i++;
		if (str[i] == '-' || ft_isdigit(str[i]))
			i++;
	}
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == '|' || str[i] == ';')
		{
			ft_putendl_fd("sh: weird syntax", 2);
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}

int		ft_file_or_dir(char *str)
{
	struct stat s;

	if (stat(str, &s) == 0)
		if (s.st_mode & S_IFREG)
			return (1);
	ft_putstr(str);
	ft_errexit(": is not a file");
	return (0);
}
