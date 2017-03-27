/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremovechars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 21:33:47 by bciss             #+#    #+#             */
/*   Updated: 2016/05/03 16:05:13 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strremovechars(char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str && str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			str[n] = str[i];
			n++;
		}
		i++;
	}
	str[n] = 0;
	return (str);
}
