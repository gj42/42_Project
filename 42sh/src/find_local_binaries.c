/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_local_binaries.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 15:13:07 by bciss             #+#    #+#             */
/*   Updated: 2016/03/28 15:13:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	is_binary(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
		return (0);
	return (S_ISREG(buf.st_mode) && (S_IXUSR & buf.st_mode));
}

static int	count_local_binaries(char *path)
{
	DIR				*dp;
	int				count;
	struct dirent	*cur;

	if ((dp = opendir(path)) == NULL)
		return (-1);
	count = 0;
	while ((cur = readdir(dp)) != NULL)
	{
		if (is_binary(cur->d_name))
			count++;
	}
	closedir(dp);
	return (count);
}

char		**find_local_binaries(char *path)
{
	DIR				*dp;
	char			**ret;
	int				i;
	size_t			len;
	struct dirent	*cur;

	if ((len = count_local_binaries(path)) == -1)
		return (NULL);
	if ((dp = opendir(path)) == NULL)
		return (NULL);
	if ((ret = (char**)malloc(sizeof(char*) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	while ((cur = readdir(dp)) != NULL)
	{
		if (is_binary(cur->d_name))
		{
			ret[i] = ft_strdup(cur->d_name);
			i++;
		}
	}
	ret[i] = NULL;
	closedir(dp);
	return (ret);
}
