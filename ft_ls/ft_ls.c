/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 10:02:20 by gjensen           #+#    #+#             */
/*   Updated: 2015/02/03 19:30:08 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addlsdir(t_lsdir **tlsdir, t_lsdir *new, char *name, char *path)
{
	t_lsdir			*temp;

	if (*tlsdir == NULL)
		*tlsdir = new;
	else
	{
		temp = *tlsdir;
		while (temp->next)
			temp = temp->next;
		new->previous = temp;
		temp->next = new;
	}
	ls_addpath(new, name, path);
	new = ls_addidandgrp(new, name);
}

t_lsdir	*ft_ls_sortascii(t_lsdir *lsdir, int exchange)
{
	t_lsdir	*tmp;

	tmp = lsdir;
	while (exchange)
	{
		exchange = 0;
		lsdir = tmp;
		while (lsdir->previous)
			lsdir = lsdir->previous;
		while (lsdir && lsdir->next)
		{
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

void	checkmode(t_lsdir *lsdir)
{
	if (S_ISDIR(lsdir->stat->st_mode))
		ft_putchar('d');
	else if (S_ISLNK(lsdir->stat->st_mode))
		ft_putchar('l');
	else if (S_ISCHR(lsdir->stat->st_mode))
		ft_putchar('c');
	else if (S_ISBLK(lsdir->stat->st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(lsdir->stat->st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(lsdir->stat->st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
	(lsdir->stat->st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	(lsdir->stat->st_mode & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	ft_putstr("  ");
}

t_lsdir	*ft_ls_sorttime(t_lsdir *lsdir, int exchange)
{
	t_lsdir	*tmp;

	tmp = lsdir;
	while (exchange)
	{
		exchange = 0;
		lsdir = tmp;
		while (lsdir->previous)
			lsdir = lsdir->previous;
		while (lsdir && lsdir->next)
		{
			if (lsdir->stat->st_mtimespec.tv_sec
					< lsdir->next->stat->st_mtimespec.tv_sec)
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
