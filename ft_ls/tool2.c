/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 13:20:22 by gjensen           #+#    #+#             */
/*   Updated: 2015/05/06 19:25:25 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_swapstr(char **a, char **b)
{
	char *i;

	i = *b;
	*b = *a;
	*a = i;
}

char		**ft_argsort(char **argv, int start, int end)
{
	int			left;
	int			right;
	const char	*pivot;

	left = start - 1;
	right = end + 1;
	pivot = argv[start];
	if (start >= end)
		return (argv);
	while (left < right)
	{
		right--;
		while (ft_strcmp(argv[right], pivot) > 0)
			right--;
		left++;
		while (ft_strcmp(argv[left], pivot) < 0)
			left++;
		if (left < right)
			ls_swapstr(&argv[left], &argv[right]);
	}
	argv = ft_argsort(argv, start, right);
	argv = ft_argsort(argv, right + 1, end);
	return (argv);
}

t_lsalign	*checkaligncut2(t_lsalign *align, t_lsdir *lsdir)
{
	int	majorl;
	int	bytes;

	if (S_ISCHR(lsdir->stat->st_mode) || S_ISBLK(lsdir->stat->st_mode))
	{
		align->minorl = 4;
		majorl = ft_intlen(MAJOR(lsdir->stat->st_rdev));
		if (majorl > align->majorl)
			align->majorl = majorl;
	}
	bytes = ft_intlen(lsdir->stat->st_size);
	if (bytes > align->bytes)
		align->bytes = bytes;
	return (align);
}

t_lsdir		*ft_ls_sorttimeascii(t_lsdir *lsdir, int exchange)
{
	t_lsdir	*tmp;

	tmp = lsdir;
	while (exchange)
	{
		exchange = 0;
		lsdir = tmp;
		while (lsdir && lsdir->next)
		{
			if (lsdir->stat->st_mtimespec.tv_sec
					== lsdir->next->stat->st_mtimespec.tv_sec)
				if (ft_strcmp(lsdir->name, lsdir->next->name) > 0)
				{
					swaplist(lsdir, lsdir->next);
					if (lsdir->next != NULL)
						lsdir->next->previous = lsdir;
					exchange = 1;
				}
			lsdir = lsdir->next;
		}
	}
	while (lsdir->previous)
		lsdir = lsdir->previous;
	return (lsdir);
}

t_lsdir		*ls_addidandgrp(t_lsdir *new, char *name)
{
	struct passwd	*id;
	struct group	*grp;

	ft_strcpy(new->name, name);
	id = getpwuid(new->stat->st_uid);
	grp = getgrgid(new->stat->st_gid);
	if (id)
		new->idn = ft_strdup(id->pw_name);
	else
		new->idn = NULL;
	if (grp)
		new->gn = ft_strdup(grp->gr_name);
	else
		new->gn = NULL;
	return (new);
}
