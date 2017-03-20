/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextodec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 21:40:41 by bciss             #+#    #+#             */
/*   Updated: 2016/04/25 19:00:54 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hextodec(char *str)
{
	int		i;
	int		e;
	int		dec;

	dec = 0;
	e = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '9')
			dec += (str[i] - '0') * ft_pow(16, e);
		else if ((str[i] >= 'A' && str[i] <= 'F'))
			dec += (str[i] - 'A' + 10) * ft_pow(16, e);
		else if ((str[i] >= 'a' && str[i] <= 'f'))
			dec += (str[i] - 'a' + 10) * ft_pow(16, e);
		i--;
		e++;
	}
	return (dec);
}
