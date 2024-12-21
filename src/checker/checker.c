/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:13:47 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/21 15:39:32 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "get_next_line.h"
#include <unistd.h>

int	errors_handler(int error);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (data == NULL || fill_stack(argc, argv, data) == -1)
		return (errors_handler(-2));
	parse_and_execute(data);
	if (is_sorted(data) != 0)
		return (errors_handler(-1));
	write(1, "OK\n", 3);
	free(data);
	return (0);
}

int	errors_handler(int error)
{
	if (error == -1 || error == -2)
		write(2, "KO\n", 3);
	else
		write(2, "Undefined error\n", 16);
	return (error);
}
