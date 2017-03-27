/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstrnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 03:00:19 by bciss             #+#    #+#             */
/*   Updated: 2016/05/05 17:40:33 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dblstrnew(size_t len)
{
	char	**ret;
	char	**tmp;
	size_t	i;

	if ((ret = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	tmp = ret;
	i = -1;
	while (++i <= len)
		tmp[i] = NULL;
	return (ret);
}
