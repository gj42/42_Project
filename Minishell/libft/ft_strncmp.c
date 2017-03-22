/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:24 by gjensen           #+#    #+#             */
/*   Updated: 2015/02/17 18:46:48 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	ts1 = (unsigned char*)s1;
	ts2 = (unsigned char*)s2;
	while ((ts1[i] || ts2[i]) && i < n)
	{
		if (ts1[i] == ts2[i])
			i++;
		else
			return (ts1[i] - ts2[i]);
	}
	return (0);
}
