/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 20:40:12 by bciss             #+#    #+#             */
/*   Updated: 2016/05/19 20:57:12 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void					free_negative(t_hist *ptr)
{
	t_hist				*tmp;

	tmp = ptr;
	while (tmp)
	{
		if (tmp->index < 0)
		{
			ptr = tmp;
			tmp = tmp->next;
			free(ptr);
			g_history = tmp;
		}
		else
			tmp = tmp->next;
	}
}

void					decrement_index(t_hist *ptr)
{
	t_hist				*tmp;

	tmp = ptr;
	while (ptr)
	{
		ptr->index--;
		ptr = ptr->next;
	}
	free_negative(tmp);
}

void					ft_add_history_file(char *time, char *str)
{
	int				fd;

	if ((fd = open(g_history_file, O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
		return ;
	write(fd, "[", 1);
	write(fd, time, ft_strlen(time));
	write(fd, "]:", 2);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	close(fd);
}

void					get_history_content(char **array, char *file)
{
	int				ret;
	int				fd;
	char			buf[0xf000];

	if ((fd = open(file, O_RDONLY | O_CREAT, 0666)) == -1)
		return ;
	if ((ret = read(fd, buf, 0xf000)) > 0)
	{
		buf[ret] = '\0';
		ft_strpatternsplit(array, buf, "]:");
	}
	close(fd);
}
