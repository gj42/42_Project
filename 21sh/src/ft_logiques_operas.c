/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logiques_operas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 03:40:13 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/11 03:41:27 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_sh.h"

int		ft_or(char *left, char *right)
{
	ft_traitement(left);
	if (g_status == 0)
		ft_traitement(right);
	return (1);
}

int		ft_and(char *left, char *right)
{
	ft_traitement(left);
	if (g_status == 1)
		ft_traitement(right);
	return (1);
}
