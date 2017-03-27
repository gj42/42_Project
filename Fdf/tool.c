/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:40:50 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/26 17:30:50 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_center(t_env *e)
{
	t_point p;
	int		yl;
	int		xl;
	double	fx;
	double	fy;

	fx = e->map->lines[0]->points[0]->x;
	fy = e->map->lines[0]->points[0]->y;
	yl = e->map->len;
	xl = e->map->lines[yl - 1]->len;
	p.x = (e->map->lines[yl - 1]->points[xl - 1]->x +
			fx) / 2;
	p.y = (e->map->lines[yl - 1]->points[xl - 1]->y +
			fy) / 2;
	e->center = p;
}

void	init_window(char *title, int weight, int height, t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		fdf_malloc_error();
	e->win = mlx_new_window(e->mlx, weight, height, title);
}

int		get_color(t_point *point1, t_point *point2)
{
	int color;
	int z;

	if (point1->z_color > point2->z_color)
		z = point1->z_color;
	else
		z = point2->z_color;
	if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x74c615;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20)
		color = 0xFAECBE;
	else
		color = 0;
	return (color);
}
