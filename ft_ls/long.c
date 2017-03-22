/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 11:58:11 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/21 21:56:54 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	showlinks(t_lsdir *lsdir, t_lsalign *align)
{
	int	space;

	space = align->links;
	while (space > ft_intlen(lsdir->stat->st_nlink))
	{
		ft_putchar(' ');
		space--;
	}
	ft_putnbr(lsdir->stat->st_nlink);
	ft_putchar(' ');
}

void	showbytes(t_lsdir *lsdir, t_lsalign *align)
{
	int space;

	if (S_ISCHR(lsdir->stat->st_mode) || S_ISBLK(lsdir->stat->st_mode))
	{
		ft_putchar(' ');
		space = align->majorl;
		while (space > ft_intlen(MAJOR(lsdir->stat->st_rdev)))
		{
			ft_putchar(' ');
			space--;
		}
		ft_putnbr(MAJOR(lsdir->stat->st_rdev));
		ft_putstr(",");
		space = align->minorl;
		while (space > ft_intlen(MINOR(lsdir->stat->st_rdev)))
		{
			ft_putchar(' ');
			space--;
		}
		ft_putnbr(MINOR(lsdir->stat->st_rdev));
		align->alignmaj = align->minorl + align->majorl + 2;
	}
	else
		showbytescut(lsdir, align);
}

void	show_id(t_lsdir *lsdir, t_lsalign *align)
{
	size_t	space;
	char	*idname;

	space = align->user;
	if (lsdir->idn)
		idname = lsdir->idn;
	else
		idname = ft_itoa(lsdir->stat->st_uid);
	free(lsdir->idn);
	ft_putstr(idname);
	while (space > ft_strlen(idname))
	{
		ft_putchar(' ');
		space--;
	}
	ft_putstr("  ");
	show_grp(lsdir, align);
}

void	showtime(time_t *clock)
{
	char	*str;
	time_t	ct;
	char	*date;
	char	*year;
	char	*hours;

	ct = time(NULL);
	if ((str = ctime(clock)) == NULL)
		return ;
	date = ft_strsub(str, 3, 7);
	ft_putstr(date);
	if (*clock > ct || *clock + 15768000 < ct)
	{
		year = ft_strsub(str, 19, 5);
		ft_putchar(' ');
		ft_putstr(year);
		ft_putchar(' ');
	}
	else
	{
		hours = ft_strsub(str, 10, 6);
		ft_putstr(hours);
		ft_putchar(' ');
	}
}
