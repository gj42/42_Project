/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:14:45 by bciss             #+#    #+#             */
/*   Updated: 2016/05/03 12:45:43 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				*get_line(char *str, char *file, unsigned int line)
{
	int				fd;

	if (!file)
		return (NULL);
	if ((fd = open(g_history_file, O_RDONLY | O_CREAT, 0666)) == -1)
	{
		perror("open");
		ft_exit("Open error6");
	}
	if (!(str = get_line_nb(line, fd, str)))
		ft_exit("Get_line error");
	close(fd);
	return (str);
}

char				*get_line_nb(unsigned int line, int fd, char *str)
{
	char			buf[0xf000];
	int				i;
	unsigned int	bs;
	int				ret;

	i = -1;
	bs = 0;
	while ((ret = read(fd, buf, 0xf000)) > 0 && bs != line)
	{
		buf[ret] = '\0';
		while (buf[++i] && bs != line)
		{
			if (buf[i] == '\n')
				bs++;
		}
	}
	return (get_line_ret(buf, i, str));
}

char				*get_line_ret(char *buf, int i, char *str)
{
	char		got[0xf000];
	int			j;

	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
	{
		got[j] = buf[i];
		j++;
		i++;
	}
	got[j] = '\n';
	got[++j] = '\0';
	return (ft_strcpy(str, got));
}

int					count_lines(t_hist *history)
{
	t_hist			*tmp;
	int				nb;

	nb = 0;
	tmp = history;
	while (tmp)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void				remove_lines(t_hist *history)
{
	t_hist			*tmp;
	int				b;

	b = 0;
	tmp = history;
	while (tmp)
	{
		if (tmp->index == 0)
			b = 1;
		if (tmp->index > HISTORY_SIZE)
		{
			b = 0;
		}
		if (tmp->index == 0 && b == 1)
			break ;
		tmp = tmp->next;
	}
}
