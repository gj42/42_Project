/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 23:54:51 by bciss             #+#    #+#             */
/*   Updated: 2016/01/14 17:41:45 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#define FLAGS_N 1
#define FLAGS_E 2

char g_sl[11] = {'\\', 'a', 'b', 'f', 'n', 'r', 't', 'v', '\"', 'e', 'c'};
char g_sl2[10] = {'\\', '\a', '\b', '\f', '\n', '\r', '\t', '\v', '\"', '\033'};

int		ft_colors(char *str, int i)
{
	int		j;
	char	tmp[4];

	j = 0;
	if (str[i + 1] == '0')
	{
		i += 2;
		while (j < 3 && ft_isocta(str[i]))
			tmp[j++] = str[i++];
		tmp[j] = '\0';
		ft_putchar(ft_octtodec((char *)tmp));
	}
	else
	{
		i += 2;
		while (j < 2 && ft_ishexa(str[i]))
			tmp[j++] = str[i++];
		tmp[j] = '\0';
		ft_putchar(ft_hextodec((char *)tmp));
	}
	return (j);
}

int		ft_special_char(char *str, int i)
{
	int		j;

	j = -1;
	while (++j < 11)
		if (str[i + 1] == '0' || str[i + 1] == 'x')
		{
			i += ft_colors(str, i);
			break ;
		}
		else if (str[i + 1] == g_sl[j])
		{
			if (j == 10)
				return (0);
			ft_putchar(g_sl2[j]);
		}
	i++;
	return (i);
}

int		writting(char *str, unsigned int flags)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\\' && !(flags & FLAGS_E))
		{
			i = ft_special_char(str, i);
		}
		else if (str[i] == '\"')
			;
		else
			ft_putchar(str[i]);
	}
	return (1);
}
