/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flood.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:21:51 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:03:13 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	free_map(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
		free(map.map[y++]);
	free(map.map);
}

t_map	duplicate_map(t_map map)
{
	t_map_element	**map_d;
	int				y;
	int				x;

	map_d = malloc(sizeof(t_map_element *) * map.height);
	if (!map_d)
		return ((t_map){.width = map.width, .height = map.height, .map = NULL});
	y = 0;
	while (y < map.height)
	{
		map_d[y] = malloc(sizeof(t_map_element) * map.width);
		if (!map_d[y])
		{
			free_map((t_map){.width = map.width,
				.height = map.height, .map = map_d});
			return ((t_map){.width = map.width,
				.height = map.height, .map = NULL});
		}
		x = -1;
		while (++x < map.width)
			map_d[y][x] = map.map[y][x];
		y++;
	}
	return ((t_map){.width = map.width,
		.height = map.height, .map = map_d});
}

int	flood_fill(t_map *map, t_position cur, int discoverable)
{
	static int		discovered = 0;
	t_map_element	elem;

	check_not_null(map, "tmap cannot be null");
	check_not_null(map->map, "map cannot be null");
	elem = map->map[cur.y][cur.x];
	if (elem == WALL)
		return (0);
	if (elem == EXIT || elem == COLLECTIBLE)
		discovered++;
	if (discovered == discoverable)
		return (1);
	if (elem == EXIT)
		return (0);
	map->map[cur.y][cur.x] = WALL;
	if (flood_fill(map, (t_position){cur.x + 1, cur.y}, discoverable))
		return (1);
	if (flood_fill(map, (t_position){cur.x - 1, cur.y}, discoverable))
		return (1);
	if (flood_fill(map, (t_position){cur.x, cur.y + 1}, discoverable))
		return (1);
	if (flood_fill(map, (t_position){cur.x, cur.y - 1}, discoverable))
		return (1);
	return (0);
}

int	check_possible_path(t_map *map)
{
	int		result;
	t_map	d_map;
	int		y;
	int		x;
	int		collectible;

	check_not_null(map, "map cannot be null.");
	d_map = duplicate_map(*map);
	check_not_null(d_map.map, "map.map could not duplicated.");
	y = 0;
	collectible = 0;
	while (y < d_map.height)
	{
		x = 0;
		while (x < d_map.width)
		{
			if (d_map.map[y][x] == EXIT || d_map.map[y][x] == COLLECTIBLE)
				collectible++;
			x++;
		}
		y++;
	}
	result = flood_fill(&d_map, get_player_position(map), collectible);
	free_map(d_map);
	return (result);
}
