#include <sys/fcntl.h>
#include <printf.h>
# include "so_long.h"
# include "get_next_line/get_next_line.h"

t_map *is_rectangular(char *path) {
	char	*line;
	int 	height;
	int		width;
	int		fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		check_is_not(1, 1, "empty maps");
	height = 1;
	width = (int) ft_strlen(line) - 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (width != (int) ft_strlen(line) - 1)
			check_is_not(1, 1, "maps is not rectangular");
		height++;
	}
	close(fd);
	t_map *map = malloc(sizeof(t_map));
	check_not_null(map, "memory allocation failed at is_rectangular()");
	map->width = width;
	map->height = height;
	return map;
}