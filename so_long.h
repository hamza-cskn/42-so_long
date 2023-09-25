/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:20:14 by hcoskun           #+#    #+#             */
/*   Updated: 2023/09/09 12:27:39 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# define PIXEL_SIZE 32

typedef enum e_map_elements {
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C',
	VISITED = 'V'
}				t_map_element;

typedef struct s_position {
	int	x;
	int	y;
}				t_position;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	int		width;
	int		height;
	t_map_element	**map;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
	int 	moves;
}				t_vars;

struct s_flood_data {
	int left_collectible;
	t_position current;
	t_map map; // 1 = wall, 0 = empty, 2 = collectible, 3 = exit, (100 > n) = visited with n - 100 length path.
	int status; //1 = found, 0 = continues, -1 abort.
};

int close_window(t_vars *vars);

// Fill Flood

struct s_flood_data flood_fill(struct s_flood_data data, unsigned int path_taken);

// Validation
t_map *validate_map(char *path);

// Map
t_map *load_map(char *path);

void safe_move(t_vars *vars, int dx, int dy);

t_position get_player_position(t_map *map);

// Controllers
void init_controllers(t_vars *vars);

// Images
t_data *get_grass_img(void *mlx);

t_data *get_player_img(void *mlx);

t_data *get_wall_img(void *mlx);

t_data *get_exit_img(void *mlx);

t_data *get_collectible_img(void *mlx);

// Visualizer

void update_entire_map(t_vars *vars);

void update_square(t_vars *vars, int x, int y);

t_data *prepare_image(void *mlx, int width, int height);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Preconditions
void *check_not_null(void *pointer, char *message);

void check_is_not(int value, int not, char *message);

void check_is(int value, int is, char *message);

void check_is_bigger(int value, int min, char *message);

void check_is_smaller(int value, int max, char *message);

void check_is_range(int value, int min, int max, char *message);

#endif