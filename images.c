#include "so_long.h"
# include <stdio.h>

t_data *get_grass_img(void *mlx) {
	t_data	*img;
	int x;
	int y;

	img = prepare_image(mlx, PIXEL_SIZE, PIXEL_SIZE);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			my_mlx_pixel_put(img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
	return img;
}

t_data *get_player_img(void *mlx) {
	t_data	*img;
	int x;
	int y;

	img = prepare_image(mlx, PIXEL_SIZE, PIXEL_SIZE);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	return img;
}

t_data *get_wall_img(void *mlx) {
	t_data	*img;
	int x;
	int y;

	img = prepare_image(mlx, PIXEL_SIZE, PIXEL_SIZE);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			my_mlx_pixel_put(img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	return img;
}

t_data *get_exit_img(void *mlx) {
	t_data	*img;
	int x;
	int y;

	img = prepare_image(mlx, PIXEL_SIZE, PIXEL_SIZE);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF00FF);
			x++;
		}
		y++;
	}
	return img;
}

t_data *get_collectible_img(void *mlx) {
	t_data	*img;
	int x;
	int y;

	img = prepare_image(mlx, PIXEL_SIZE, PIXEL_SIZE);
	y = 0;
	while (y < PIXEL_SIZE)
	{
		x = 0;
		while (x < PIXEL_SIZE)
		{
			my_mlx_pixel_put(img, x, y, 0x00FFFF00);
			x++;
		}
		y++;
	}
	return img;
}