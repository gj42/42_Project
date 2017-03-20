/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 01:43:59 by bciss             #+#    #+#             */
/*   Updated: 2016/03/11 05:23:58 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupc(const char *src, char c)
{
	int		i;
	char	*str;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * (ft_strlenc(src, c) + 1))) == NULL)
		return (NULL);
	while (src[i] && src[i] != c)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
