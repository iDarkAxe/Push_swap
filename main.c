/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:39:03 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 16:13:03 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

/*@TODO REMOVE*/
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (remplissage_stacks(argc, argv, data) == -1)
		return (-1);
	if (DEBUG == 1)
		print_stacks(data);
	printf("\nFIN DU REMPLISSAGE\n\n");
	ft_sb(data);
	if (DEBUG == 1)
		print_stacks(data);
	return (0);
}
