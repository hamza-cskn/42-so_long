# include "so_long.h"
# include <stdio.h>
#include <time.h>

void free_map(t_map map) {
	int y = 0;
	while (y < map.height)	
		free(map.map[y++]);
	free(map.map);
}

// colored print map
void print_map(t_map map) {
	int y = 0;
	while (y < map.height) {
		int x = 0;
		while (x < map.width) {
			if (map.map[y][x] >= 100)
				printf("\033[0;31mV\033[0m ");
			else if (map.map[y][x] == COLLECTIBLE)
				printf("\033[0;32m%c\033[0m ", map.map[y][x]);
			else if (map.map[y][x] == PLAYER)
				printf("\033[0;33m%c\033[0m ", map.map[y][x]);
			else if (map.map[y][x] == EXIT)
				printf("\033[0;34m%c\033[0m ", map.map[y][x]);
			else if (map.map[y][x] == WALL)
				printf("\033[0;35m%c\033[0m ", map.map[y][x]);
			else
				printf("0 ");
			x++;
		}
		printf("\n");
		y++;
	}
}

t_map duplicate_map(t_map map) {
	t_map_element **map_d = malloc(sizeof(t_map_element *) * map.height);
	if (!map_d)
		return (t_map){.width = map.width, .height = map.height, .map = NULL};
	int y = 0;
	while (y < map.height) {
		map_d[y] = malloc(sizeof(t_map_element) * map.width);
		if (!map_d[y])
		{
			free_map((t_map){.width = map.width, .height = map.height, .map = map_d});
			return (t_map){.width = map.width, .height = map.height, .map = NULL};
		}
		int x = 0;
		while (x < map.width) {
			map_d[y][x] = map.map[y][x];
			x++;
		}
		y++;
	}
	return (t_map){.width = map.width, .height = map.height, .map = map_d};
}

struct s_flood_data copy_flood_data(t_map map, struct s_flood_data data, int dx, int dy)
{
	return (struct s_flood_data){
		.status = 0,
		.left_collectible = data.left_collectible,
		.current = (t_position){.x = data.current.x + dx, .y = data.current.y + dy},
		.map = map};
}

struct s_flood_data best_path(struct s_flood_data data1, struct s_flood_data data2) {

	if (data1.status > data2.status) // status numbers are priorities. (1 = exit found, 0 = continues, -1 = aborted (wall or visited found))
		return data1;
	if (data1.status < data2.status)
		return data2;
	if (data1.left_collectible > data2.left_collectible)
		return data1;
	if (data1.left_collectible < data2.left_collectible)
		return data2;
	return data1; // there is no best.
}

struct s_flood_data flood_fill(struct s_flood_data data, unsigned int path_taken) {
	static unsigned int shortest_path = 1000000;
	static clock_t start_time = 0;

	check_not_null(data.map.map, "map is null");
	t_map_element element = data.map.map[data.current.y][data.current.x];

	if (element >= 100 && element - 100 <= path_taken) //if visited before with shorter path, abort.
		return (struct s_flood_data){.status = -1};	// return abort.

	// check if current position is out of bounds.
	if (element == WALL || data.current.x < 0 || data.current.x >= data.map.width || data.current.y < 0 || data.current.y >= data.map.height)
		return (struct s_flood_data){.status = -1}; // return abort.

	if (element == COLLECTIBLE)
		data.left_collectible--; // collect and continue spreading.

	if (element == EXIT) {
		if (data.left_collectible == 0) {
			if (path_taken < shortest_path) {
				shortest_path = path_taken;
				if (start_time != 0)
					printf("time elapsed: %fms\n", (double)(clock() - start_time) / (CLOCKS_PER_SEC / 1000));
				start_time = clock();
				printf("found shorter exit, path_taken %d:\n", path_taken);
				print_map(data.map);
			}
			return (struct s_flood_data) {.status = 1}; // return found.
		} else
			return (struct s_flood_data) {.status = -1};
	}

	if (element >= 100)
		return (struct s_flood_data){.status = -1}; // return abort.

	t_map map_d = duplicate_map(data.map);
	check_not_null(map_d.map, "map could not duplicated.");
	map_d.map[data.current.y][data.current.x] = 100 + path_taken; // mark as visited.

	struct s_flood_data best;
	best = flood_fill(copy_flood_data(map_d, data, 1, 0), path_taken + 1);
	if (best.status == 1)
		return best;
	best = best_path(best, flood_fill(copy_flood_data(map_d, data, 0, 1), path_taken + 1));
	if (best.status == 1)
		return best;
	best = best_path(best, flood_fill(copy_flood_data(map_d, data, -1, 0), path_taken + 1));
	if (best.status == 1)
		return best;
	best = best_path(best, flood_fill(copy_flood_data(map_d, data, 0, -1), path_taken + 1));
	free_map(map_d);
	return best;
}