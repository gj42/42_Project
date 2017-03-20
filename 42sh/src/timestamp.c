/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 23:46:02 by bciss             #+#    #+#             */
/*   Updated: 2016/05/16 11:06:28 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "get_next_line.h"
#include <time.h>

int				get_timestamp(void)
{
	return ((int)time(NULL));
}

char			*ft_get_read(void)
{
	char		*tmp;
	char		buf[0xf000];
	int			ret;

	tmp = NULL;
	if ((ret = read(0, buf, 0xf000)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strdup(buf);
		return (tmp);
	}
	return (NULL);
}
