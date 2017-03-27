/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 11:09:45 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/27 16:25:58 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_linescut(t_point *p1, t_point *p2, double *dxy, double *tab)
{
	p1->x -= p1->z;
	p1->y -= p1->z;
	p2->y -= p2->z;
	p2->x -= p2->z;
	dxy[0] = fabs(p2->x - p1->x);
	dxy[1] = fabs(p2->y - p1->y);
	tab[0] = (dxy[0] > dxy[1] ? dxy[0] : -dxy[1]) * 0.5;
}

void	draw_lines(t_env *e, t_point p1, t_point p2)
{
	double dxy[2];
	double sxy[2];
	double tab[2];
	double p[2];

	draw_linescut(&p1, &p2, dxy, tab);
	sxy[0] = p1.x < p2.x ? 1 : -1;
	sxy[1] = p1.y < p2.y ? 1 : -1;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		p[0] = p1.x + ((WINDOW_SIZE_W - (e->center.x * 2)) / 2);
		p[1] = p1.y + ((WINDOW_SIZE_H - (e->center.y * 2)) / 2);
		mlx_pixel_put(e->mlx, e->win, p[0], p[1], get_color(&p1, &p2));
		tab[1] = tab[0];
		if (tab[1] > -dxy[0])
		{
			tab[0] -= dxy[1];
			p1.x += sxy[0];
		}
		if (tab[1] < dxy[1])
		{
			tab[0] += dxy[0];
			p1.y += sxy[1];
		}
	}
}
