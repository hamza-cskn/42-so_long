/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:45:05 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:04:57 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include "minilibx/mlx.h"

int	check_format(char *filename)
{
	return (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) == 0);
}

void	safe_image_free(void *mlx, void *pointer)
{
	if (pointer)
		mlx_destroy_image(mlx, pointer);
}
