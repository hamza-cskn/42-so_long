#include "so_long.h"
#include <stdio.h>

t_data *prepare_image(void *mlx, int width, int height) {
	t_data	*img = (t_data *) malloc(sizeof(t_data));

	img->img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								  &img->endian);
	check_not_null(img, "malloc allocation failed at prepare_image()");
	return img;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	check_not_null(data, "data not found\n");
	check_not_null(data->addr, "address not found\n");
	check_is_not(data->line_length, 0, "line length cannot be zero\n");
	check_is_not(data->bits_per_pixel, 0, "bits per pixel cannot be zero\n");
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void update_square(t_vars *vars, int x, int y) {
	t_map_elements element;
	t_data *img;

	element = vars->map->map[y][x];
	printf("%c\n", element);
	if (element == EMPTY)
		img = get_grass_img(vars->mlx);
	else if (element == PLAYER)
		img = get_player_img(vars->mlx);
	else if (element == WALL)
		img = get_wall_img(vars->mlx);
	else if (element == EXIT)
		img = get_exit_img(vars->mlx);
	else if (element == COLLECTIBLE)
		img = get_collectible_img(vars->mlx);
	else
		return;
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, x * PIXEL_SIZE, (vars->map->height - y - 1) * PIXEL_SIZE);
	free(img);
}

void	update_entire_map(t_vars *vars) {
	int x;
	int y;

	y = 0;
	while (y < vars->map->height) {
		x = 0;
		while (x < vars->map->width) {
			update_square(vars, x, y);
			printf("x: %d\n", x);
			x++;
		}
		y++;
	}
}