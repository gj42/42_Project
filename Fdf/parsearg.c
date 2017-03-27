/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 19:19:11 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/27 16:34:38 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fd_check_points(char *line, int nb_line, t_point ***point)
{
	char	**str;
	t_point	*a_point;
	int		i;

	str = ft_strsplit(line, ' ');
	i = 0;
	while (str[i] != NULL)
		i++;
	if (!((*point) = (t_point**)malloc(sizeof(t_point) * (i + 1))))
		fdf_malloc_error();
	i = 0;
	while (str[i] != NULL)
	{
		a_point = (t_point*)malloc(sizeof(t_point));
		a_point->y = ((nb_line + i) * SIZE_H) / 2;
		a_point->x = (i - nb_line) * SIZE_W;
		a_point->z = ft_atoi(str[i]);
		a_point->z_color = a_point->z;
		(*point)[i] = a_point;
		i++;
	}
	(*point)[i] = NULL;
	return (i);
}

int		fd_line_n(char *map)
{
	int		fd;
	int		nb_lines;
	char	buf;

	fd = 0;
	nb_lines = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (0);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			nb_lines++;
	}
	close(fd);
	return (nb_lines);
}

t_map	*fd_parse(char **argv, int fd, int nb_lines)
{
	char	*line;
	t_line	*line_map;
	t_map	*map;
	t_point	**point;

	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
	!(map->lines = (t_line**)malloc(sizeof(t_line) * fd_line_n(argv[1]) + 1)))
		fdf_malloc_error();
	map->len = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(line_map = (t_line*)malloc(sizeof(t_line))))
				fdf_malloc_error();
			line_map->len = fd_check_points(line, nb_lines, &point);
			line_map->points = point;
			map->lines[nb_lines] = line_map;
			if (line_map->len)
				nb_lines++;
		}
		map->lines[nb_lines] = NULL;
		map->len = nb_lines;
	}
	return (map);
}
