/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:39:08 by hcoskun           #+#    #+#             */
/*   Updated: 2023/09/09 12:29:12 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(" <map name>\n", 2);
		return 1;
	}

	vars.moves = 0;
	//create maps
	vars.map = load_map(ft_strjoin("./maps/", av[1]));
	struct s_flood_data flood_res = flood_fill((struct s_flood_data) {
													   .left_collectible = 3,
													   .current = get_player_position(vars.map),
													   .map = *vars.map,
													   .status = 0 },
											   0);
	check_is(flood_res.status, 1, "map is not solvable");

	// create window
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map->width * PIXEL_SIZE, vars.map->height * PIXEL_SIZE, "So Long");

	update_entire_map(&vars);
	init_controllers(&vars);
	mlx_loop(vars.mlx);
}
