/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:49:43 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:03:13 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

typedef struct s_map_requirements
{
	int		player;
	int		exit;
	int		collectible;
	int		width;
	int		height;
}	t_map_requirements;

t_map_requirements	*init_map_requirement(void)
{
	t_map_requirements	*requirements;

	requirements = malloc(sizeof(t_map_requirements));
	requirements = check_not_null(requirements, "memory allocation failed..");
	requirements->player = 0;
	requirements->exit = 0;
	requirements->collectible = 0;
	requirements->width = 0;
	requirements->height = 1;
	return (requirements);
}

int	count_char(char *line, char c)
{
	int	count;

	count = 0;
	while (*line)
		if (*line++ == c)
			count++;
	return (count);
}

void	collect_req_datas(t_map_requirements *requirements, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != WALL || line[len - 2] != WALL)
		check_is_not(1, 1, "map is not surrounded with walls.");
	requirements->player += count_char(line, PLAYER);
	requirements->exit += count_char(line, EXIT);
	requirements->collectible += count_char(line, COLLECTIBLE);
	check_is(requirements->width, len - 1, "the map is not rectangular");
	while (*line)
	{
		if (*line != WALL && *line != EMPTY && *line != PLAYER
			&& *line != EXIT && *line != COLLECTIBLE && *line != '\n')
			check_is_not(1, 1, "map contains invalid characters");
		line++;
	}
}

t_map	*convert_to_map(t_map_requirements *requirements)
{
	t_map				*map;

	check_is(requirements->player, 1, "player not found/duplicated in map");
	check_is(requirements->exit, 1, "exit not found/duplicated in map");
	check_is_not(requirements->collectible, 0, "collectible not found in maps");
	map = check_not_null(malloc(sizeof(t_map)), "memory allocation failed.");
	map->width = requirements->width;
	map->height = requirements->height;
	free(requirements);
	return (map);
}

t_map	*validate_map(char *path)
{
	char				*line;
	int					fd;
	int					wall_row;
	t_map_requirements	*requirements;

	wall_row = 0;
	requirements = init_map_requirement();
	fd = open(path, O_RDONLY);
	line = check_not_null(get_next_line(fd), "maps is empty or not found");
	requirements->width = (int) ft_strlen(line) - 1;
	if (count_char(line, WALL) != requirements->width)
		check_is_not(1, 1, "maps is not surrounded with walls.");
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		wall_row = count_char(line, WALL) == requirements->width;
		collect_req_datas(requirements, line);
		requirements->height++;
	}
	if (!wall_row)
		check_is_not(1, 1, "maps is not surrounded with walls.");
	return (close(fd), convert_to_map(requirements));
}
