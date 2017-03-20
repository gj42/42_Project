/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 22:06:38 by bciss             #+#    #+#             */
/*   Updated: 2016/05/20 16:09:28 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static char		*sh_find_var(char *str, int *i)
{
	int		x;
	char	var[0xF000];

	ft_bzero(var, 0xF000);
	x = 0;
	(*i)++;
	while (str[*i] && str[*i] != '\'' && str[*i] != '\"' &&
		str[*i] != '\\' && str[*i] != '/' && str[*i] != '$' && str[*i] != '~')
	{
		var[x] = str[*i];
		x++;
		(*i)++;
	}
	var[x] = 0;
	if (!ft_strlen(var))
		return ("$");
	return (sh_get_env_var(var));
}

static void		sh_treat_envar_in(char *ret, char *str, t_parse *p)
{
	while (str[p->i])
	{
		if (str[p->i] == '\\')
			p->flagb = p->flagb ? 0 : 1;
		if (str[p->i] == '\'')
			p->flag = p->flag ? 0 : 1;
		if (str[p->i] == '$' && !p->flag && !p->flagb)
		{
			p->val = sh_find_var(str, &(p->i));
			if (p->val)
			{
				ft_strcat(ret, p->val);
				p->n = p->n + ft_strlen(p->val);
			}
		}
		else if (str[p->i])
		{
			if (str[p->i] == '$' && p->flagb)
				p->flagb = 0;
			ret[p->n] = str[p->i];
			(p->i)++;
			(p->n)++;
		}
	}
	ret[p->n] = 0;
}

char			*sh_treat_envvar(char *str)
{
	char	*send;
	char	ret[0xF000];
	t_parse	*p;

	p = (t_parse*)malloc(sizeof(t_parse));
	p->val = NULL;
	p->flag = 0;
	p->flagb = 0;
	p->i = 0;
	p->n = 0;
	ft_bzero(ret, 0xF000);
	sh_treat_envar_in(ret, str, p);
	ft_strdel(&str);
	free(p);
	if (ft_strlen(ret) == 0)
		return (NULL);
	send = ft_strdup(ret);
	return (send);
}

static char		**sh_handle_var(char **parsed)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (parsed[i])
	{
		parsed[i] = sh_treat_envvar(parsed[i]);
		if (parsed[i] == NULL)
		{
			n = i;
			while (parsed[n + 1])
			{
				parsed[n] = parsed[n + 1];
				n++;
			}
			parsed[n] = NULL;
		}
		else
			i++;
	}
	return (parsed);
}

char			**parse_command(char *str)
{
	char	**parsed;
	int		i;

	i = 0;
	parsed = ft_smartsplit(str, ' ');
	parsed = sh_handle_var(parsed);
	while (parsed[i])
	{
		parsed[i] = sh_treatinib(parsed[i]);
		if (parsed[i][0] == '~')
			if (!(parsed[i] = manage_tilde(parsed[i])))
			{
				ft_arrfree(&parsed);
				return (NULL);
			}
		i++;
	}
	parsed = sh_handle_equal_var(parsed);
	if (parsed[0] == NULL)
	{
		free(parsed);
		return (NULL);
	}
	return (parsed);
}
