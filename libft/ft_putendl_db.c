/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 21:04:30 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 01:01:19 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_db(char *target, char *result)
{
	if (!target || !result)
		return ;
	ft_putstr(target);
	ft_putstr(" = ");
	ft_putendl(result);
}
