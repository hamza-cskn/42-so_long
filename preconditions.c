/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preconditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:46:30 by hcoskun           #+#    #+#             */
/*   Updated: 2023/09/09 12:27:17 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

void print_and_abort(char *message) {
	while (message && *message)
		write(2, message++, 1);
	exit(1);
}

void *check_not_null(void *pointer, char *message) {
	if (!pointer)
		print_and_abort(message);
	return pointer;
}

void check_is_not(int value, int not, char *message) {
	if (value == not)
		print_and_abort(message);
}

void check_is(int value, int is, char *message) {
	if (value != is)
		print_and_abort(message);
}