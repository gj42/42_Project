/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:39:30 by bciss             #+#    #+#             */
/*   Updated: 2016/04/13 18:39:33 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_strcatf(char *dest, char *src, int n)
{
	int		i;

	i = -1;
	ft_bzero(dest, ft_strlen(dest));
	while (src[n++])
		dest[++i] = src[n];
	dest[++i] = '\0';
	return (dest);
}
