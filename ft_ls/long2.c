/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:59:00 by gjensen           #+#    #+#             */
/*   Updated: 2015/01/15 21:27:06 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	showbytescut(t_lsdir *lsdir, t_lsalign *align)
{
	int space;

	space = align->bytes + align->alignmaj;
	while (space > ft_intlen(lsdir->stat->st_size))
	{
		ft_putchar(' ');
		space--;
	}
	ft_putnbr(lsdir->stat->st_size);
}

void	show_grp(t_lsdir *lsdir, t_lsalign *align)
{
	size_t	space;
	char	*grname;

	space = align->grp;
	if (lsdir->gn)
		grname = lsdir->gn;
	else
		grname = ft_itoa(lsdir->stat->st_gid);
	ft_putstr(grname);
	free(lsdir->gn);
	while (space > ft_strlen(grname))
	{
		ft_putchar(' ');
		space--;
	}
	ft_putstr("  ");
}
