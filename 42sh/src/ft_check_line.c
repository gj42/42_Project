/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:09:07 by bciss             #+#    #+#             */
/*   Updated: 2016/05/18 16:13:08 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_bad_start(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' &&
			(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '&' || str[i] == '|' || str[i] == ';')
	{
		return (1);
	}
	return (0);
}

int		ft_check_end(char *str)
{
	if (ft_bad_start(str))
	{
		ft_putendl_fd("\n""42sh""syntax error\n", 2);
		return (-2);
	}
	return (0);
}

int		ft_check_need_line(char *str)
{
	if (ft_quotes_quota(str) || ft_missing_operator(str) ||
			ft_end_with_pipe(str))
	{
		return (-1);
	}
	return (0);
}

int		niark(char *str, int i, char *c)
{
	if (c)
	{
		if (c[0] == ';' || c[0] == '|' || c[0] == '&')
		{
			if (check_adjacent(str, i + 1))
				return (-2);
		}
		else if (c[0] == '>' || c[0] == '<')
		{
			if (check_adjacent_red(str, i + 1) == 1)
				return (-2);
		}
	}
	return (0);
}

int		ft_check_key_words(char *str)
{
	int			i;
	int			r;
	char		*c;
	static char	*cara = ";><|&";

	i = 0;
	if ((r = ft_check_end(str)) != 0)
		return (r);
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			i++;
		else
		{
			c = ft_strchr(cara, str[i]);
			if (niark(str, i, c) == -2)
				return (-2);
		}
		i++;
	}
	if ((r = ft_check_need_line(str)) != 0)
		return (r);
	return (0);
}
