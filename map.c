# include "so_long.h"
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

t_map *load_map(char *path) {
	t_map	*map;
	int		y;
	int		x;
	int 	fd;
	char	*line;

	map = is_rectangular(path); //find height and width of maps
	printf("height: %d, width: %d\n", map->height, map->width);
	map->map = malloc(sizeof(t_map_elements *) * map->height);
	check_not_null(map->map, "memory allocation failed at load_map().maps");
	fd = open(path, O_RDONLY);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		printf("%d x, %d y", x, y);
		map->map[y] = malloc(sizeof(t_map_elements) * map->width);
		check_not_null(map->map[y], "memory allocation failed at load_map().maps[y]");
		line = get_next_line(fd);
		while (x < map->width)
		{
			map->map[y][x] = (t_map_elements) line[x];
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	return map;
}

void validate_map()
{

}

t_position get_player_position(t_map *map)
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
				return (t_position){.x = x, .y = y};
			x++;
		}
		y++;
	}
	check_is_not(1, 1, "player not found in maps");
	return (t_position){.x = -1, .y = -1};
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

void safe_move(t_vars *vars, int dx, int dy) {
	t_position player;
	int x;
	int y;

	player = get_player_position(vars->map);
	x = player.x + dx;
	y = player.y + dy;
	if (vars->map->map[y][x] == WALL)
		return;
	if (vars->map->map[y][x] == EXIT)
	{
		if (is_any_collectible_exist(vars->map))
			return;
		printf("You win!\n");
		close_window(vars);
		return;
	}
	vars->map->map[player.y][player.x] = EMPTY;
	vars->map->map[y][x] = PLAYER;
	update_square(vars, player.x, player.y);
	update_square(vars, x, y);
}