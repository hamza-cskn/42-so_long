/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:20:14 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:04:17 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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

typedef struct s_map {
	int				width;
	int				height;
	t_map_element	**map;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
	int		moves;
}				t_vars;

t_vars		*get_vars(char *filename);

void		abort_game(void);

int			close_window(void);

// Fill Flood
int			check_possible_path(t_map *map);

void		free_map(t_map map);

// Validation
t_map		*validate_map(char *path);

// Map
t_map		*load_map(char *path);

void		safe_move(t_vars *vars, int dx, int dy);

t_position	get_player_position(t_map *map);

// Controllers
void		init_controllers(t_vars *vars);

// Images
void		*get_grass_img(t_vars *vars, int enforce_cache);

void		*get_player_img(t_vars *vars, int enforce_cache);

void		*get_wall_img(t_vars *vars, int enforce_cache);

void		*get_exit_img(t_vars *vars, int enforce_cache);

void		*get_collectible_img(t_vars *vars, int enforce_cache);

// Visualizer

void		update_entire_map(t_vars *vars);

void		update_square(t_vars *vars, int x, int y);

// Preconditions
void		*check_not_null(void *pointer, char *message);

void		check_is_not(int value, int not, char *message);

void		check_is(int value, int is, char *message);

// Utils

void		safe_image_free(void *mlx, void *pointer);

int			check_format(char *filename);

#endif