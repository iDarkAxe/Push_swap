/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:13:47 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/28 23:03:18 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "get_next_line.h"
#include <unistd.h>

static int	errors_handler(int error, t_data *data);
static int	init_data(t_data *data);

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
		return (errors_handler(-1, data));
	if (fill_stack(argc, argv, data) != 0)
		return (errors_handler(-2, data));
	parse_and_execute(data);
	if (is_sorted(data) != 0)
		return (errors_handler(-1, data));
	write(1, "OK\n", 3);
	ft_stackclear(data);
	return (0);
}

/**
 * @brief Handles multiple errors types
 * 
 * @param error 
 * @param data 
 * @return int 
 */
static int	errors_handler(int error, t_data *data)
{
	if (error == -1 || error == -2)
		write(2, "KO\n", 3);
	else
		write(2, "Undefined error\n", 16);
	ft_stackclear(data);
	return (error);
}

/**
 * @brief Initialize Data to avoid using calloc
 * 
 * @param data 
 * @return int 
 */
static int	init_data(t_data *data)
{
	if (data == NULL)
		return (-1);
	data->a = NULL;
	data->b = NULL;
	data->a_len = 0;
	data->b_len = 0;
	return (0);
}
