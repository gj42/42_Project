/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 23:55:26 by bciss             #+#    #+#             */
/*   Updated: 2016/05/11 17:22:48 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		check_adjacent(char *str, int i)
{
	if (str[0] == ';' || str[0] == '|' || str[0] == '&')
	{
		ft_putstr_fd("sh: weird syntax near ->", 2);
		ft_putchar_fd(str[0], 2);
		return (0);
	}
	if ((str[i] == '|' && str[i - 1] == '|') || (str[i] == '&' &&
				str[i - 1] == '&'))
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ';' || str[i] == '|' || str[i] == '&')
		{
			ft_putstr_fd("sh: weird syntax near ->", 2);
			ft_putchar_fd(str[i], 2);
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (0);
}

int		check_adjacent_opera(char *str, int i)
{
	if (str[0] == '&' || str[0] == '|')
	{
		ft_putstr_fd("sh: weird syntax near ->", 2);
		ft_putchar_fd(str[0], 2);
		return (0);
	}
	if (str[i] == str[i - 1])
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '&' || str[i] == '|')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

int		ft_quotes_quota(char *str)
{
	int		i;
	char	c;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\\')
			i++;
		else
		{
			if (str[i] == '\"' || str[i] == '\'')
			{
				c = str[i++];
				while (1)
				{
					if (str[i] == c && str[i - 1] != '\\')
						break ;
					else if (str[i] == '\0')
						return (2);
					i++;
				}
			}
		}
	}
	return (0);
}

int		ft_missing_operator(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i > 1 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
				|| str[i] == '|' || str[i] == '&'))
	{
		if ((str[i] == '|' && str[i - 1] == '|') ||
				(str[i] == '&' && str[i - 1] == '&'))
			return (1);
		i--;
	}
	return (0);
}

int		ft_end_with_pipe(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (i > 1 && (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
				|| str[i] == '|'))
	{
		if (str[i] == '|')
			return (1);
		i--;
	}
	return (0);
}
