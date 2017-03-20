/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:27:02 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 23:43:22 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char				**autocomp_all(char *path)
{
	char			**tb;
	struct dirent	*rd;
	DIR				*rep;
	int				i;

	i = 0;
	if (!(rep = opendir(path)))
		ft_exit("Opendir failed");
	while ((rd = readdir(rep)))
		i++;
	closedir(rep);
	if (i == 0)
		return (NULL);
	if (!(tb = (char**)malloc(sizeof(char*) * i + 1)))
		ft_exit("Malloc error");
	tb[i + 1] = NULL;
	i = -1;
	if (!(rep = opendir(path)))
		ft_exit("Opendir failed");
	while ((rd = readdir(rep)))
		tb[++i] = ft_strdup(rd->d_name);
	closedir(rep);
	return (tb);
}

char				*autocomp_word(char *str, char *path)
{
	struct dirent	*rd;
	DIR				*rep;
	int				i;
	char			**tb;

	if (((i = -1) == -1) && !str)
		return (ft_select(autocomp_all(path)));
	if ((i = get_tab_size(path, str) == 0))
		return (str);
	if (!(tb = (char**)malloc(sizeof(char*) * i + 1)))
		ft_exit("Malloc error");
	if (!(rep = opendir(path)))
		ft_exit("Opendir failed");
	i = -1;
	while ((rd = readdir(rep)))
		if (!(ft_strncmp(str, rd->d_name, ft_strlen(str))))
			tb[++i] = ft_strdup(rd->d_name);
	if (i == -1)
		ft_arrfree(&tb);
	if (i == -1)
		return (str);
	closedir(rep);
	if (((tb[i + 1] = NULL) == NULL) && tb[1] && tb[1][0] == '\0')
		return (tb[0]);
	return (ft_select(tb));
}

char				*autocomp_command(char *str, char *path, int i)
{
	struct dirent	*rd;
	DIR				*rep;
	int				j;
	char			**tb;
	char			**sp;

	j = -1;
	sp = ft_strsplit(path, ':');
	tb = autocomp_size(str, path, i);
	if (!tb)
		return (str);
	while (sp[++j])
	{
		if (!(rep = opendir(sp[j])))
			return (NULL);
		while ((rd = readdir(rep)))
			if (!(ft_strncmp(str, rd->d_name, ft_strlen(str))))
				tb[++i] = ft_strdup(rd->d_name);
		closedir(rep);
	}
	tb[++i] = NULL;
	ft_arrfree(&sp);
	return (ft_select(tb));
}

char				**autocomp_size(char *str, char *path, int i)
{
	struct dirent	*rd;
	DIR				*rep;
	char			**sp;
	char			**tb;
	int				y;

	y = 0;
	if (!(sp = ft_strsplit(path, ':')))
		return (NULL);
	while (sp[++i])
	{
		if (!(rep = opendir(sp[i])))
			return (NULL);
		while ((rd = readdir(rep)))
			if (!(ft_strncmp(str, rd->d_name, ft_strlen(str))))
				y++;
		closedir(rep);
	}
	if (y == 0 || y == 1)
		return (NULL);
	if (!(tb = (char **)malloc(sizeof(char*) * (y + 1))))
		ft_exit("Malloc error");
	ft_arrfree(&sp);
	return (tb);
}
