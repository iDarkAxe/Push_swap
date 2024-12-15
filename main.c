/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:39:03 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 17:37:10 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

/*@TODO REMOVE*/
#include <stdio.h>

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
	if (data == NULL || fill_stack(argc, argv, data) == -1)
		return (-1);
	print_stacks(data);
	printf("\nFIN DU REMPLISSAGE\n\n");
	print_stacks(data);
	return (0);
}
