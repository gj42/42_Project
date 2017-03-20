/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 13:54:59 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 06:00:00 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void			ft_copy(void)
{
	ft_traitement("pbcpy");
}

char			*insert_str_index(char *buffer, int *cursor, char *str)
{
	int		i;
	int		j;
	char	*ret;
	size_t	len;

	len = ft_strlen(buffer) + ft_strlen(str) + 1;
	if ((ret = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (buffer[++i] && i < *cursor)
		ret[i] = buffer[i];
	while (str[++j])
		ret[i + j] = str[j];
	while (buffer[i])
	{
		ret[i + j] = buffer[i];
		i++;
	}
	*cursor = *cursor + ft_strlen(str);
	ret[i + j] = '\0';
	ft_strdel(&str);
	return (ret);
}

char			*ft_paste(void)
{
	pid_t	pid;
	int		fd[2];
	int		ret;
	char	*tmp;
	char	buf[0xf000];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_traitement("pbpaste");
		exit(0);
	}
	close(fd[1]);
	wait(NULL);
	while ((ret = read(fd[0], buf, 0xf000)) > 0)
	{
		buf[ret] = '\0';
	}
	tmp = ft_strdup(buf);
	return (tmp);
}
