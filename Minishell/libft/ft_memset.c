/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:06:30 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/08 17:52:33 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tb;

	tb = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		tb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
