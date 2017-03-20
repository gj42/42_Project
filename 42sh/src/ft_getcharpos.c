/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcharpos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 00:29:23 by bciss             #+#    #+#             */
/*   Updated: 2016/05/03 12:25:05 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_getcharpos(char *str, char c, int a)
{
	int		i;

	i = 0;
	if (a)
	{
		if (c == '|')
		{
			i = ft_strlen(str) - 1;
			while (i > 0)
			{
				if (str[i] == c)
					return (i);
				i--;
			}
		}
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
