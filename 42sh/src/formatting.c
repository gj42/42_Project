/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:08:22 by bciss             #+#    #+#             */
/*   Updated: 2016/05/12 04:46:19 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char	*ft_formatting(char *str)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strspetrim(str, 0, 0);
	ret = ft_calias(tmp);
	if (tmp)
		ft_strdel(&tmp);
	return (ret);
}
