/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:39:21 by gjensen           #+#    #+#             */
/*   Updated: 2014/11/11 13:43:54 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*ts1 != *ts2)
			return (*ts1 - *ts2);
		ts1++;
		ts2++;
		i++;
	}
	return (0);
}
