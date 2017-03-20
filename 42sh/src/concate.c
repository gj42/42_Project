/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:59:33 by bciss             #+#    #+#             */
/*   Updated: 2016/02/24 01:18:49 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*concate(char *first, char *second, char *separator)
{
	size_t	length;
	char	*new;

	length = ft_strlen(first) + ft_strlen(second) + ft_strlen(separator) + 1;
	new = (char*)malloc(sizeof(*new) * length);
	if (new == NULL)
		return (NULL);
	if ((new = ft_strcpy(new, first)) == NULL)
		return (NULL);
	if ((new = ft_strcat(new, separator)) == NULL)
		return (NULL);
	return ((new = ft_strcat(new, second)));
}
