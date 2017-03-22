/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managestart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 04:25:40 by gjensen           #+#    #+#             */
/*   Updated: 2015/02/03 19:05:43 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_checkarg(char c)
{
	if (!(c == 'l' || c == 'R' || c == 'a' || c == 'r' || c == 't' || c == '-'
				|| c == '1'))
	{
		ft_putstr(TITLE);
		ft_putstr(": ");
		ft_putstr(" illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ft_putstr("usage: ");
		ft_putstr(TITLE);
		ft_putendl(" [-lRart] [file ...]");
		exit(1);
	}
}

void		showblocks(t_lsdir *lsdir, t_lsalign *align, t_lsoption *option)
{
	if (!option->optiona)
	{
		while (lsdir->next && (lsdir->name[0] == '.'
					&& lsdir->stat->st_mode))
			lsdir = lsdir->next;
		if (lsdir->name[0] != '.')
		{
			ft_putstr("total ");
			ft_putnbr(align->totalblocks);
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("total ");
		ft_putnbr(align->totalblocks);
		ft_putchar('\n');
	}
}

t_lsdir		*ls_sort_lsdir(t_lsdir *lsdir, t_lsoption *option)
{
	if (option->optiont)
	{
		lsdir = ft_ls_sorttime(lsdir, 1);
		lsdir = ft_ls_sorttimeascii(lsdir, 1);
	}
	else
		lsdir = ft_ls_sortascii(lsdir, 1);
	return (lsdir);
}

void		ft_startlscut(t_lsdir *lsdir, t_lsoption *option,
		t_lsalign *align, DIR *dir)
{
	if (dir && option->optionl)
		showblocks(lsdir, align, option);
	if (option->optionr)
	{
		while (lsdir && lsdir->next)
			lsdir = lsdir->next;
	}
	while (lsdir && !option->hidden)
	{
		if (!option->optiona)
		{
			if (lsdir->name[0] != '.' || dir == NULL)
				printls(lsdir, align, option);
		}
		else
			printls(lsdir, align, option);
		if (option->optionr)
			lsdir = lsdir->previous;
		else
			lsdir = lsdir->next;
	}
}

int			ft_parsecut(t_lsoption *option, char **argv, int i)
{
	int j;

	while (argv[i] && (argv[i][0] == '-'))
	{
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				return (i + 1);
			ft_checkarg(argv[i][j]);
			if (argv[i][j] == 'l')
				option->optionl = 1;
			if (argv[i][j] == 'R')
				option->optionrr = 1;
			if (argv[i][j] == 'a')
				option->optiona = 1;
			if (argv[i][j] == 'r')
				option->optionr = 1;
			if (argv[i][j] == 't')
				option->optiont = 1;
			j++;
		}
		i++;
	}
	return (i);
}
