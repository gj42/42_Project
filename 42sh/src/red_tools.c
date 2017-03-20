/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 20:02:36 by bciss             #+#    #+#             */
/*   Updated: 2016/05/31 21:35:52 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include "libft.h"

void	ft_fd_from(char **tb, t_data *d)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	while (tb[++k])
	{
		i = ft_strlen(tb[k]) - 1;
		if (i > 0 && (tb[k][i - 1] == ' ' || tb[k][i - 1] == '\t')
				&& ft_isdigit(tb[k][i]))
		{
			j = ft_atoi(tb[k] + i);
			tb[k][i] = '\0';
			d->aggre[k] = j;
		}
		else
			d->aggre[k] = 1;
	}
	d->aggre[k] = -1;
}

int		check_valid(char *str)
{
	if (((str[0] == '>' || str[0] == '<') && (str[1] == '>' || str[1] == '<') &&
			(str[2] == '&') && (str[3] == '-' || ft_isdigit(str[3]) ||
				str[3] == ' ')) || ((str[0] == '>' || str[0] == '<') &&
				(str[1] == '&') && (str[2] == '-' || ft_isdigit(str[2]) ||
					str[2] == ' ')))
		return (1);
	return (0);
}

void	ft_where(char **tb, t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tb[++i])
		if (check_valid(tb[i]))
		{
			if (tb[i][2] == '-')
			{
				if (tb[i - 1][ft_strlen(tb[0]) - 1] == '1')
					close(1);
				else if (tb[i - 1][ft_strlen(tb[0]) - 1] == '2')
					close(2);
			}
			else if (tb[i][2] == '1' || tb[i][2] == ' ')
				d->spefd[i] = 1;
			else if (tb[i][2] == '2')
				d->spefd[i] = 2;
			else
			{
				ft_putendl_fd("Bad file descriptor", 2);
				d->spefd[0] = 0;
			}
		}
}

int		check_check(char *str)
{
	if (check_valid(str))
		return (1);
	return (0);
}

void	ft_errexit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
	return ;
}
