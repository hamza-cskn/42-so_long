# include "so_long.h"
# include <stdio.h>

enum e_keys {
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
};

int key_hook(int keycode, t_vars *vars) {
	printf("keycode: %d\n", keycode);
	printf("mlx: %p\n", vars->mlx);
	if (keycode == ESC)
		close_window(vars);
	else if (keycode == W)
		safe_move(vars, 0, 1);
	else if (keycode == A)
		safe_move(vars, -1, 0);
	else if (keycode == S)
		safe_move(vars, 0, -1);
	else if (keycode == D)
		safe_move(vars, 1, 0);
	return 0;
}

void init_controllers(t_vars *vars) {
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars);
}

