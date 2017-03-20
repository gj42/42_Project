/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 03:08:17 by bciss             #+#    #+#             */
/*   Updated: 2015/04/08 03:27:34 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapstr(char **str, char **str2)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	*str = ft_strdup(*str2);
	*str2 = ft_strdup(*str);
	free(tmp);
}
