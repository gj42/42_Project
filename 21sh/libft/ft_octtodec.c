/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octtodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:15:32 by vdaviot           #+#    #+#             */
/*   Updated: 2016/04/25 19:01:47 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_octtodec(char *str)
{
	int	i;
	int	e;
	int	dec;

	dec = 0;
	e = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] >= '0' && str[i] <= '7')
			dec += (str[i] - '0') * ft_pow(8, e);
		i--;
		e++;
	}
	return (dec);
}