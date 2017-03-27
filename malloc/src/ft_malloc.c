/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:55:21 by gjensen           #+#    #+#             */
/*   Updated: 2016/12/12 15:54:26 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page	*g_firstpage;

void	print_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	get_system_limit(size_t size)
{
	size_t			total;
	struct rlimit	rlp;

	getrlimit(RLIMIT_AS, &rlp);
	total = rlp.rlim_cur;
	if (total < size)
		print_error("Not enough space available");
}

void	*malloc(size_t size)
{
	void		*ptr;
	static int	init;

	if (!init)
	{
		init = 1;
		g_firstpage = NULL;
	}
	get_system_limit(size);
	ptr = do_malloc(size);
	return (ptr);
}
