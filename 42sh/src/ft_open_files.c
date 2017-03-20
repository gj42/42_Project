/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:58:25 by bciss             #+#    #+#             */
/*   Updated: 2016/03/11 21:27:50 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	ft_open_file(char *tb)
{
	while (tb[i])
	{
		tmp = ft_get_word(tb[i] + ((tb[i][1] == '<' ||
			tb[i][1] == '>') ? 2 : 1), 1, 0);
		if (tb[i][0] == '>' && tb[i][1] == '>')
			fd[i - 1] = open(ft_strtrim(tmp), O_RDWR |
				O_CREAT | O_APPEND, 0666);
		else if (tb[i][0] == '>')
			fd[i - 1] = open(ft_strtrim(tmp), O_RDWR | O_CREAT | O_TRUNC, 0666);
		i++;
	}
	return ;
}
