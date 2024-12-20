/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:39:03 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/20 16:41:07 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
#include <unistd.h>

/*@TODO REMOVE*/
#include <stdio.h>

int	errors_handler(int error);

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
	int		return_value;

	if (argc == 1)
		return (-1);
	// write(1, "Start\n", 6);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (errors_handler(-1));
	return_value = fill_stack(argc, argv, data);
	if (return_value == -1)
		return (errors_handler(-2));
	if (return_value != 0)
		return (errors_handler(-2));
	// print_stacks(data);
	if (ft_sort(data) != 0)
	{
		free(data);
		print_stacks(data);
		return (errors_handler(-3));
	}
	// write(1, "End\n", 5);
	free(data);
	// print_stacks(data);
	// printf("size = %ld", data->a_len);
	return (0);
}

int	errors_handler(int error)
{
	if (error == -1)
		write(2, "Error\n", 6);
	if (error == -2)
		write(2, "Error remplissage\n", 18);
	if (error == -3)
		write(2, "Error, ce n'est pas trié\n", 27);
	return (error);
}
