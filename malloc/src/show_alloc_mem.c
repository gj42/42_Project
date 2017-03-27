/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:18:29 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 16:01:47 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	print_type_name(char type)
{
	if (type == TINY)
		ft_putstr("TINY");
	else if (type == SMALL)
		ft_putstr("SMALL");
	else if (type == LARGE)
		ft_putstr("LARGE");
}

static void	print_datas(void *ptr, size_t size)
{
	print_adress(ptr);
	ft_putstr(" - ");
	print_adress(ptr + size);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putendl(" octets");
}

void		show_alloc_mem(void)
{
	t_page	*page;
	t_mdata	*mdata;

	if ((page = g_firstpage))
	{
		while (page)
		{
			print_type_name(page->type);
			ft_putstr(" : ");
			print_adress(page->start);
			ft_putchar('\n');
			mdata = page->start;
			while (mdata)
			{
				if (!mdata->free)
					print_datas(mdata + 1, mdata->size);
				mdata = mdata->next;
			}
			page = page->next;
		}
	}
}
