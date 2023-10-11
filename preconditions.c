/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preconditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:46:30 by hcoskun           #+#    #+#             */
/*   Updated: 2023/10/01 18:02:00 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

void	print_and_abort(char *message)
{
	write(2, "Error\n", 7);
	while (message && *message)
		write(2, message++, 1);
	write(2, "\n", 1);
	abort_game();
	exit(1);
}

void	*check_not_null(void *pointer, char *message)
{
	if (!pointer)
		print_and_abort(message);
	return (pointer);
}

void	check_is_not(int value, int not, char *message)
{
	if (value == not)
		print_and_abort(message);
}

void	check_is(int value, int is, char *message)
{
	if (value != is)
		print_and_abort(message);
}
