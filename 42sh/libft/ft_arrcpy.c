/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:05:29 by bciss             #+#    #+#             */
/*   Updated: 2015/05/09 19:36:38 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **arr)
{
	char	**new_arr;
	t_uint	pos;

	if (!(new_arr = (char**)malloc(sizeof(char*) * (ft_arrlen(arr) + 1))))
		return (NULL);
	pos = 0;
	while (arr && arr[pos])
	{
		new_arr[pos] = ft_strdup(arr[pos]);
		pos++;
	}
	new_arr[pos] = NULL;
	return (new_arr);
}
