/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <gjensen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:20:58 by gjensen           #+#    #+#             */
/*   Updated: 2015/03/26 17:23:32 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_exit(void)
{
	exit(1);
}

void	fdf_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	fdf_exit();
}

void	fdf_map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	fdf_exit();
}

void	fdf_arg_error(void)
{
	ft_putstr_fd("Fdf: usage: ./fdf mapname.fdf\n", 2);
	fdf_exit();
}

int		main(int argc, char **argv)
{
	t_env	*e;
	t_map	*map;

	if (argc == 2)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			fdf_malloc_error();
		map = fd_parse(argv, 0, 0);
		if (map->len == 0)
			fdf_map_error();
		e->map = map;
		get_center(e);
		init_window("Fdf", WINDOW_SIZE_W, WINDOW_SIZE_H, e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_loop(e->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
