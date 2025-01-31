/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:00:06 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/31 09:51:38 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Main function
 * /!\ require arguments to work
 *
 * @param argc number of argument
 * @param argv array of string
 * @return int 0 OK, -1 is error
 */
int	ft_pushswap(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (-1);
	if (init_data(&data) != 0)
		return (errors_handler(-1, &data));
	if (verify_arguments(argc, argv) != 0)
		return (errors_handler(-4, &data));
	if (fill_stack(argc, argv, &data) != 0)
		return (errors_handler(-2, &data));
	if (ft_sort(&data) != 0)
		return (errors_handler(-3, &data));
	ft_stackclear(&data);
	return (0);
}

/**
 * @brief Handles multiple errors types
 *
 * @param error Identifier of error
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
int	errors_handler(int error, t_data *data)
{
	if (DEBUG == 1)
		print_stacks(data, 2);
	write(2, "Error\n", 6);
	ft_stackclear(data);
	return (error);
}

/**
 * @brief Initialize Data to avoid using calloc
 *
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
int	init_data(t_data *data)
{
	if (data == NULL)
		return (-1);
	data->a = NULL;
	data->b = NULL;
	data->a_len = 0;
	data->b_len = 0;
	return (0);
}
