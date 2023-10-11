/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:39:08 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/03 12:21:35 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

void	abort_game(void)
{
	t_vars	*vars;

	vars = get_vars(NULL);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->map)
		free_map(*(vars->map));
	safe_image_free(vars->mlx, get_grass_img(vars, 1));
	safe_image_free(vars->mlx, get_player_img(vars, 1));
	safe_image_free(vars->mlx, get_wall_img(vars, 1));
	safe_image_free(vars->mlx, get_exit_img(vars, 1));
	safe_image_free(vars->mlx, get_collectible_img(vars, 1));
}

t_vars	*get_vars(char *filename)
{
	static t_vars	vars;

	if (filename == NULL)
		return (&vars);
	vars.moves = 0;
	vars.map = load_map(ft_strjoin("./maps/", filename));
	check_is_not(check_possible_path(vars.map), 0, "No possible path found.");
	vars.mlx = check_not_null(mlx_init(), "Mlx could not initialized.");
	vars.win = mlx_new_window(vars.mlx, vars.map->width * PIXEL_SIZE,
			vars.map->height * PIXEL_SIZE, "So Long");
	return (&vars);
}

int	close_window(void)
{
	abort_game();
	exit(0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ", 2);
		ft_putstr_fd(av[0], 2);
		ft_putstr_fd(" <map name>\n", 2);
		return (1);
	}
	check_is_not(check_format(av[1]), 0, "Name of map is formatted properly.");
	vars = get_vars(av[1]);
	update_entire_map(vars);
	init_controllers(vars);
	mlx_loop(vars -> mlx);
}
