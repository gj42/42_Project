/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:49:42 by gjensen           #+#    #+#             */
/*   Updated: 2016/04/12 17:46:10 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#define FLAGS_N 1
#define FLAGS_E 2

int		echo_option(char *str, unsigned int *flags, int j)
{
	int		i;

	i = 1;
	if (str[0] == '-')
	{
		i = 1;
		while (str[i] != '\0')
		{
			if (str[i] == 'n')
				*flags |= FLAGS_N;
			else if (str[i] == 'E')
				*flags |= FLAGS_E;
			else
				return (j);
			i++;
		}
	}
	return (j + 1);
}

void	put_echo(char **tb, unsigned int flags, int start)
{
	int		i;
	int		j;

	i = start;
	j = 1;
	while (tb[i] && j)
	{
		j = writting(tb[i++], flags);
		if (tb[i])
			ft_putchar(' ');
	}
	if (!(flags & FLAGS_N) && j)
		ft_putchar('\n');
	return ;
}

int		ft_echo(char **tb)
{
	int				start;
	int				i;
	unsigned int	flags;

	start = 1;
	i = 0;
	while (tb[++i] && tb[i][0] == '-')
		start = echo_option(tb[i], &flags, i);
	put_echo(tb, flags, start);
	ft_setenv("_", "echo");
	return (1);
}
