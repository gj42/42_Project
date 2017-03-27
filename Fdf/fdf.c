/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:45:18 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/26 15:20:10 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_map(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	draw_map(t_env *e)
{
	int		y;
	int		x;
	t_point	p1;

	y = 0;
	while (y < e->map->len)
	{
		x = 0;
		while (x < e->map->lines[y]->len)
		{
			p1 = (*e->map->lines[y]->points[x]);
			if (e->map->lines[y + 1])
				if (e->map->lines[y + 1]->points[x]
						&& x <= e->map->lines[y + 1]->len)
					draw_lines(e, p1, *e->map->lines[y + 1]->points[x]);
			if (e->map->lines[y]->points[x + 1])
				draw_lines(e, p1, *e->map->lines[y]->points[x + 1]);
			x++;
		}
		y++;
	}
}
