/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:49:54 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 17:02:32 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	update_square(t_vars *vars, int x, int y)
{
	t_map_element	element;
	void			*img;
	int				size;

	size = PIXEL_SIZE;
	element = vars->map->map[y][x];
	if (element == EMPTY)
		img = get_grass_img(vars, 0);
	else if (element == PLAYER)
		img = get_player_img(vars, 0);
	else if (element == WALL)
		img = get_wall_img(vars, 0);
	else if (element == EXIT)
		img = get_exit_img(vars, 0);
	else if (element == COLLECTIBLE)
		img = get_collectible_img(vars, 0);
	else
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win,
		get_grass_img(vars, 0), x * PIXEL_SIZE, y * PIXEL_SIZE);
	mlx_put_image_to_window(vars->mlx, vars->win,
		img, x * PIXEL_SIZE, y * PIXEL_SIZE);
}

void	update_entire_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map->height)
	{
		x = 0;
		while (x < vars->map->width)
		{
			update_square(vars, x, y);
			x++;
		}
		y++;
	}
}
