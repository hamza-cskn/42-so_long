/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:42:39 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:03:13 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

t_map	*load_map(char *path)
{
	t_map	*map;
	int		y;
	int		x;
	int		fd;
	char	*line;

	map = validate_map(path);
	fd = open(path, O_RDONLY);
	free(path);
	map->map = malloc(sizeof(t_map_element *) * map->height);
	check_not_null(map->map, "memory allocation failed at load_map().maps");
	y = 0;
	while (y < map->height)
	{
		x = -1;
		map->map[y] = malloc(sizeof(t_map_element) * map->width);
		check_not_null(map->map[y], "memory allocation failed");
		line = get_next_line(fd);
		while (++x < map->width)
			map->map[y][x] = (t_map_element) line[x];
		free(line);
		y++;
	}
	close(fd);
	return (map);
}

t_position	get_player_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == PLAYER)
				return ((t_position){.x = x, .y = y});
			x++;
		}
		y++;
	}
	check_is_not(1, 1, "player not found in maps");
	return ((t_position){.x = -1, .y = -1});
}

int	is_any_collectible_exist(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == COLLECTIBLE)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	safe_move(t_vars *vars, int dx, int dy)
{
	t_position	player;
	int			x;
	int			y;

	player = get_player_position(vars->map);
	x = player.x + dx;
	y = player.y + dy;
	if (vars->map->map[y][x] == WALL)
		return ;
	if (vars->map->map[y][x] == EXIT)
	{
		if (is_any_collectible_exist(vars->map))
			return ;
		ft_putstr_fd("You win!\n", 1);
		close_window();
		return ;
	}
	vars->map->map[player.y][player.x] = EMPTY;
	vars->map->map[y][x] = PLAYER;
	update_square(vars, player.x, player.y);
	update_square(vars, x, y);
	vars->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr_fd("\n", 1);
}
