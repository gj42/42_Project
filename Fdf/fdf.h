/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 23:13:37 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/27 16:27:37 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define SIZE_W 30
# define SIZE_H 30
# define WINDOW_SIZE_H 1000
# define WINDOW_SIZE_W 2000

typedef struct		s_point
{
	double	y;
	double	x;
	double	z;
	double	s;
	int		z_color;
}					t_point;

typedef struct		s_line
{
	t_point	**points;
	int		len;
}					t_line;

typedef struct		s_map
{
	t_line	**lines;
	int		len;
}					t_map;

typedef struct		s_env
{
	t_map	*map;
	void	*mlx;
	void	*win;
	t_point	center;
}					t_env;

t_map				*fd_parse(char **argv, int fd, int nb_lines);
int					fd_check_points(char *line, int nb_line, t_point ***point);
int					ft_getnbr(char *str);
void				draw_map(t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					get_next_line(int const fd, char **line);
int					fd_line_n(char *map);
void				get_center(t_env *e);
void				init_window(char *title, int weight, int height, t_env *e);
void				draw(t_env *e, t_point *p1, t_point *p2);
void				fdf_exit(void);
void				fdf_malloc_error(void);
void				fdf_map_error(void);
void				fdf_arg_error(void);
int					get_color(t_point *point1, t_point *point2);
void				draw_linescut(t_point *p1, t_point *p2, double *dxy,
		double *tab);
void				draw_lines(t_env *e, t_point p1, t_point p2);
#endif
