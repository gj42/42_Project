/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:52:53 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/19 21:23:41 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char			*history_buffer_check(char *str, char *buf, int *line, int nb)
{
	if (*line > 0)
		(*line)--;
	if (*line == 0)
	{
		ft_bzero(str, 0xf000);
		ft_strcpy(str, buf);
		return (str);
	}
	else
		return (ft_get_line_history(str, nb - ((*line) + 1)));
}
