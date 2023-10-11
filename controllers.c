/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:22:54 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 17:17:01 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "minilibx/mlx.h"

enum e_keys {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
};

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_window();
	else if (keycode == W)
		safe_move(vars, 0, -1);
	else if (keycode == A)
		safe_move(vars, -1, 0);
	else if (keycode == S)
		safe_move(vars, 0, 1);
	else if (keycode == D)
		safe_move(vars, 1, 0);
	return (0);
}

void	init_controllers(t_vars *vars)
{
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
}
