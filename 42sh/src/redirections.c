/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:27:47 by bciss             #+#    #+#             */
/*   Updated: 2016/05/31 21:35:46 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"
#include "fcntl.h"

char	*linking(char **tb)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	while (tb[i])
	{
		if (((tb[i][0] == '>' || tb[i][0] == '<') && (tb[i][1] == '&'))
				|| ((tb[i][0] == '>' || tb[i][0] == '<') &&
					(tb[i][1] == '>' || tb[i][1] == '<') && tb[i][2] == '&'))
			str = ft_get_word(tb[i], 2, 1);
		else
			str = ft_get_word(tb[i], 3, 1);
		if (str)
			tb[0] = ft_strfreejoin(tb[0], str);
		i++;
		ft_strdel(&str);
	}
	tmp = ft_strdup(tb[0]);
	ft_strdel(&tb[0]);
	return (tmp);
}

char	*red_handl(t_data *d, char *tmp, char *tbo, char **tb)
{
	char	buf[0xf000];
	char	buff[0xf000];

	if (tb[d->i][0] == '<' && tb[d->i][1] != '<' && ft_file_or_dir(tmp))
	{
		d->fd2 = open(ft_strtrim(tmp), O_RDONLY, 0666);
		if (d->fd2 > -1)
		{
			ft_bzero(buf, 0xf000);
			ft_bzero(buff, 0xf000);
			while ((d->ret = read(d->fd2, buf, 2047)) > 0)
			{
				buf[d->ret] = '\0';
				ft_strcat(buff, buf);
			}
			tbo = ft_strdup(buff);
		}
		else
		{
			ft_errexit("open error");
		}
	}
	return (tbo);
}

char	*red_handll(t_data *d, char *tmp, char *tbo, char **tb)
{
	char	buf[0xfff];
	char	*ptr;

	if (tb[d->i][0] == '<' && tb[d->i][1] == '<')
	{
		ft_bzero(buf, 0xfff);
		ptr = buf;
		ft_putstr_cursor(buf, 0);
		while (ptr[ft_strlen(ptr) - 1] != '\n')
		{
			ft_strcpy(buf, ft_edit(ptr, tmp));
			signal(SIGINT, exit);
		}
		tbo = ft_strfreejoin(tbo, buf);
	}
	tbo = red_handl(d, tmp, tbo, tb);
	return (tbo);
}

char	*red_handler(t_data *d, char **tb)
{
	char	*tmp;
	char	*tbo;
	int		ret;

	tbo = ft_strdup("\0");
	tmp = ft_get_word(tb[d->i] +
			((tb[d->i][1] == '<' || tb[d->i][1] == '>') ? 2 : 1), 1, 0);
	if (tb[d->i][0] == '>' && tb[d->i][1] == '>' && ft_file_or_dir(tmp))
	{
		ret = open(ft_strtrim(tmp), O_RDWR | O_CREAT | O_APPEND, 0666);
		if (ret >= 0)
			d->fd[d->i - 1] = ret;
		else
			ft_errexit("open error");
	}
	else if (tb[d->i][0] == '>' && ft_file_or_dir(tmp))
	{
		ret = open(ft_strtrim(tmp), O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (ret >= 0)
			d->fd[d->i - 1] = ret;
		else
			ft_errexit("open error");
	}
	tbo = red_handll(d, tmp, tbo, tb);
	return (tbo);
}

void	ft_trafic_regulator(char **tb)
{
	char	*tbo;
	t_data	d;
	char	*tmp;

	d.spefd[0] = 1;
	d.j = 0;
	d.i = 0;
	d.fd[0] = 0;
	ft_where(tb, &d);
	if (!d.spefd[0])
		exit(0);
	ft_fd_from(tb, &d);
	while (tb[++d.i])
		if (!check_check(tb[d.i]))
			tbo = red_handler(&d, tb);
	d.fd[d.i - 1] = 0;
	tb[0] = linking(tb);
	red_pipe((tmp = ft_strsupertrim(tb[0])), d, tbo);
	ft_strdel(&tmp);
	exit(0);
}
