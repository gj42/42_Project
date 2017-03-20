/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:08:25 by bciss             #+#    #+#             */
/*   Updated: 2016/05/03 12:49:31 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void		pre_red(char *str)
{
	int		i;
	int		r;
	int		ret;
	char	*tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '>' && str[i + 1] != '&' && str[i + 1] != '>') ||
				(str[i] == '>' && str[i + 1] == '>' && str[i + 2] != '&'))
		{
			r = ((str[i + 1] == '>') ? 2 : 1);
			tmp = ft_get_word(str + i + r, 1, 0);
			ret = open(tmp, O_CREAT, 0666);
			ft_strdel(&tmp);
			close(ret);
			i = i + r - 1;
		}
		i++;
	}
	return ;
}
