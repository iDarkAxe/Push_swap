/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:39:03 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/29 00:07:47 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
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
	if (ft_sort(data) != 0)
	{
		print_stacks(data);
		return (errors_handler(-3, data));
	}
	ft_stackclear(data);
	return (0);
}

/**
 * @brief Handles multiple errors types
 * 
 * @param error Identifier of error
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
static int	errors_handler(int error, t_data *data)
{
	if (error == -1)
		write(2, "Error\n", 6);
	if (error == -2)
		write(2, "Error remplissage\n", 18);
	if (error == -3)
		write(2, "Error, ce n'est pas trié\n", 27);
	ft_stackclear(data);
	return (error);
}

/**
 * @brief Initialize Data to avoid using calloc
 * 
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
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
