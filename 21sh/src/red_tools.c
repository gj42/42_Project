/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 20:02:36 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/03 12:50:51 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"

int		ft_fd_from(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str) - 1;
	if (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t')
			&& ft_isdigit(str[i]))
	{
		j = ft_atoi(str + i);
		str[i] = '\0';
		return (j);
	}
	return (1);
}

int		ft_where(char **tb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tb[++i])
	{
		if ((tb[i][1] == '&') && (tb[i][2] == '-' || ft_isdigit(tb[i][2])))
		{
			if (tb[i][2] == '-')
			{
				close(1);
				close(2);
			}
			else if (tb[i][2] == '1')
				return (1);
			else if (tb[i][2] == '2')
				return (2);
			else
				ft_putendl_fd("Bad file descriptor", 2);
		}
	}
	return (0);
}

int		check_check(char *str)
{
	if (((str[0] == '<' || str[0] == '>') &&
				(str[1] == '&' && ft_isdigit(str[2]))) ||
			((str[1] == '<' || str[1] == '>') &&
			str[2] == '&' && ft_isdigit(str[3])))
		return (1);
	return (0);
}

/*
** void	ft_check_parse(char **tb)
** {
** 	int		i;
** 	int		j;
** 	i = 1;
** 	while (tb[i])
** 	{
** 		j = 0;
** 		c = tb[i];
** 		while (tb[i][j] != '\0')
** 		{
** 			while (tb[i][j] != '\0')
** 			{
** 				if
** 			}
** 			j++;
** 		}
** 		i++;
** 	}
** 	return ;
** }
*/

void	ft_errexit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
	return ;
}
