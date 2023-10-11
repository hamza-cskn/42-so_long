/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:56:27 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:01:07 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

void	*get_grass_img(t_vars *vars, int enforce_cache)
{
	static int	size = PIXEL_SIZE;
	static void	*img = 0;

	if (!img)
	{
		if (enforce_cache)
			return (0);
		img = mlx_xpm_file_to_image(vars->mlx, "images/gras.xpm", &size, &size);
	}
	check_not_null(img, "Grass image could not loaded");
	return (img);
}

void	*get_player_img(t_vars *vars, int enforce_cache)
{
	static int	size = PIXEL_SIZE;
	static void	*img = 0;

	if (!img)
	{
		if (enforce_cache)
			return (0);
		img = mlx_xpm_file_to_image(vars->mlx, "images/play.xpm", &size, &size);
	}
	check_not_null(img, "Player image could not loaded");
	return (img);
}

void	*get_exit_img(t_vars *vars, int enforce_cache)
{
	static int	size = PIXEL_SIZE;
	static void	*img = 0;

	if (!img)
	{
		if (enforce_cache)
			return (0);
		img = mlx_xpm_file_to_image(vars->mlx, "images/exit.xpm", &size, &size);
	}
	check_not_null(img, "Exit image could not loaded");
	return (img);
}

void	*get_wall_img(t_vars *vars, int enforce_cache)
{
	static int	size = PIXEL_SIZE;
	static void	*img = 0;

	if (!img)
	{
		if (enforce_cache)
			return (0);
		img = mlx_xpm_file_to_image(vars->mlx, "images/wall.xpm", &size, &size);
	}
	check_not_null(img, "Wall image could not loaded");
	return (img);
}

void	*get_collectible_img(t_vars *vars, int enforce_cache)
{
	static int	size = PIXEL_SIZE;
	static void	*img = 0;

	if (!img)
	{
		if (enforce_cache)
			return (0);
		img = mlx_xpm_file_to_image(vars->mlx, "images/coll.xpm", &size, &size);
	}
	check_not_null(img, "Collectible image could not loaded");
	return (img);
}
