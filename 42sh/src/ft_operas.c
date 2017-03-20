/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 00:33:41 by bciss             #+#    #+#             */
/*   Updated: 2016/05/03 14:33:35 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#define IF_(x) if(x) {
#define ELSE(x) } else x
#define ENDIF }
#define DBA(x, y, z, w) x = y; z = w;
#define WHILE(x) while(x) {
#define ENDWHILE }
#define INIT(x, y, z) x y = z;
#define COUNTC(x, y) ft_countc(x, y)

int	(*g_calculette[6])(char *left, char *right) = {ft_or, ft_and, ft_pipe};
static char	g_opera_char[3] = {'|', '&', '|'};
static char	g_rc[2] = {'>', '<'};

int					ft_is_opera(char *str)
{
	int			i;
	static char	*g_opera[3] = {"||", "&&", "|"};

	i = 0;
	while (i < 3)
	{
		if (ft_strstr(str, g_opera[i]))
			return (i);
		i++;
	}
	return (-1);
}

int					red_is(char *str)
{
	int			i;
	int			j;
	static char	g_rc[2] = {'>', '<'};

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 2)
		{
			if (str[i] == g_rc[j])
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

static int			ft_truc2(char *str, int i)
{
	char		*left;
	char		*right;
	int			j;

	j = ft_getcharpos(str, g_opera_char[i], (i == 2) ? 1 : 0);
	left = ft_strsub(str, 0, j);
	right = ft_strdup(str + j + ((i < 2) ? 2 : 1));
	g_calculette[i](left, right);
	ft_strdel(&left);
	ft_strdel(&right);
	return (1);
}

static int			ft_truc(char **tb)
{
	pid_t		pid;

	pid = fork();
	save_cpid(&pid);
	if (pid == 0)
		ft_trafic_regulator(tb);
	else
		wait(NULL);
	pid = 0;
	save_cpid(&pid);
	ft_arrfree(&tb);
	return (1);
}

int					ft_opera_handler(char *str)
{
	int			k;
	char		**tb;

	INIT(int, i, ft_is_opera(str));
	if (i >= 0)
		return (ft_truc2(str, i));
	i = red_is(str);
	IF_(i >= 0);
	tb = malloc(sizeof(char *) * (COUNTC(str, '>') + COUNTC(str, '<') + 2));
	INIT(int, j, ft_getcharpos(str, g_rc[i], 0));
	DBA(k, 0, tb[k++], ft_strsub(str, 0, j));
	str = str + j;
	WHILE(i >= 0 && j >= 0);
	j = ft_getcharpos(str + ((str[1] == g_rc[i]) ? 2 : 1), g_rc[i], 0);
	IF_(j >= 0);
	tb[k++] = ft_strsub(str, 0, j + ((str[1] == g_rc[i]) ? 2 : 1));
	str = str + ((j > 0) ? j : 1) + ((str[1] == g_rc[i]) ? 2 : 1);
	i = red_is(str);
	ELSE(tb[k++] = ft_strdup(str));
	ENDWHILE;
	tb[k] = NULL;
	return (ft_truc(tb));
	ENDIF;
	return (-2);
}
