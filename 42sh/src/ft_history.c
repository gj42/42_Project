/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 07:41:25 by bciss             #+#    #+#             */
/*   Updated: 2016/04/22 07:47:19 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int	print_history(char **arg)
{
	int		fd;
	int		r;
	char	buf[0xf000];

	(void)arg;
	fd = open(g_history_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((r = read(fd, &buf, 0xf000)) > 0)
	{
		buf[r] = '\0';
		ft_putstr(buf);
	}
	return (1);
}
