/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:39:08 by hcoskun           #+#    #+#             */
/*   Updated: 2023/08/16 16:55:51 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	//create maps
	vars.map = load_map("./maps/map1.ber");

	// create window
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map->width * PIXEL_SIZE, vars.map->height * PIXEL_SIZE, "So Long");

	update_entire_map(&vars);
	init_controllers(&vars);
	mlx_loop(vars.mlx);
}
