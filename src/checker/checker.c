/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:13:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/02 22:49:03 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "get_next_line.h"
#include <unistd.h>

/**
 * @brief Main function
 * /!\ require arguments to work
 *
 * @param argc number of argument
 * @param argv array of string
 * @return int 0 OK, -1 is error
 */
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (init_data(data) != 0)
		return (errors_handler(-4, data));
	if (fill_stack(argc, argv, data) != 0)
		return (errors_handler(-5, data));
	parse_and_execute(data);
	if (is_sorted(data) != 0)
		return (errors_handler(-6, data));
	write(1, "OK\n", 3);
	ft_stackclear(data);
	return (0);
}
