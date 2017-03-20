/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_term2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 00:22:24 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 00:23:55 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int					ft_precision(char *str, size_t len)
{
	size_t		i;
	size_t		size;

	i = 0;
	if (!str || len < 1)
		return (0);
	size = ft_strlen(str) - 2;
	while (i < (len - size))
	{
		ft_putchar(' ');
		i++;
	}
	return (1);
}

struct winsize		*get_term_size(int *x, int *y)
{
	struct winsize	w;
	struct winsize	*ptr;

	ptr = &w;
	if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
		ft_exit("ioctl error");
	*x = w.ws_col;
	*y = w.ws_row;
	return (ptr);
}

int					get_col_term(void)
{
	struct winsize	w;
	int				x;

	x = 0;
	if ((ioctl(0, TIOCGWINSZ, &w)) == -1)
		ft_exit("ioctl error");
	x = w.ws_col;
	return (x);
}
