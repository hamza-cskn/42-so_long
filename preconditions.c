/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preconditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoskun <hcoskun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:46:30 by hcoskun           #+#    #+#             */
/*   Updated: 2023/08/16 16:18:52 by hcoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

void print_and_abort(char *message) {
	while (message && *message)
		write(1, message++, 1);
	exit(1);
}

void check_not_null(void *pointer, char *message) {
	if (!pointer)
		print_and_abort(message);
}

void check_is_not(int value, int not, char *message) {
	if (value == not)
		print_and_abort(message);
}

void check_is(int value, int is, char *message) {
	if (value != is)
		print_and_abort(message);
}

void check_is_bigger(int value, int min, char *message) {
	if (value <= min)
		print_and_abort(message);
}

void check_is_smaller(int value, int max, char *message) {
	if (value > max)
		print_and_abort(message);
}

void check_is_range(int value, int min, int max, char *message) {
	check_is_bigger(value, min, message);
	check_is_smaller(value, max, message);
}