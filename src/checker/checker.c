/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:13:47 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/20 17:23:24 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include <stddef.h>

/**
 * @brief Find differences between first and second
 *
 * @param first
 * @param second
 * @param length
 * @return int value of first - second
 */
int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	index;

	index = 0;
	while (index < (length - 1) && first[index] != '\0' && second[index] != '\0'
		&& first[index] == second[index])
		index++;
	return ((unsigned char)first[index] - (unsigned char)second[index]);
}

void	parse_and_execute(t_data *data, const char *instructions)
{
	while (*instructions != '\0')
	{
		if (ft_strncmp(instructions, "sa\n", 3) == 0)
			ft_sa(data);
		else if (ft_strncmp(instructions, "sb\n", 3) == 0)
			ft_sb(data);
		else if (ft_strncmp(instructions, "ss\n", 3) == 0)
			ft_ss(data);
		else if (ft_strncmp(instructions, "pa\n", 3) == 0)
			ft_pa(data);
		else if (ft_strncmp(instructions, "pb\n", 3) == 0)
			ft_pb(data);
		else if (ft_strncmp(instructions, "ra\n", 3) == 0)
			ft_ra(data);
		else if (ft_strncmp(instructions, "rb\n", 3) == 0)
			ft_rb(data);
		else if (ft_strncmp(instructions, "rra\n", 4) == 0)
			ft_rra(data);
		else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
			ft_rrb(data);
		else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
			ft_rrr(data);
		else if (ft_strncmp(instructions, "rr\n", 3) == 0)
			ft_rr(data);
		else
			printf("Error: Unknown instruction '%3s'\n", instructions);
		while (*instructions != '\0' && *instructions != '\n')
			instructions++;
		if (*instructions == '\n')
			instructions += 1;
	}
}

#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_data	*data;
	ssize_t	bytes_read;
	char	array[BUFFER_SIZE];
	int		fd;

	if (argc == 1)
		return (-1);
	bytes_read = read(0, array, BUFFER_SIZE);
	data = malloc(sizeof(t_data));
	if (data == NULL || fill_stack(argc, argv, data) == -1 || bytes_read == -1)
	{
		write(2, "ErroR\n", 6);
		return (-1);
	}
	array[bytes_read] = '\0';
	parse_and_execute(data, array);
	if (is_sorted(data) != 0)
	{
		write(2, "ErrOR sorting\n", 14);
		fd = open("BUG.txt", O_WRONLY | O_CREAT);
		write(fd, array, strlen(array));
		close(fd);
		printf("\nINSTRUCTIONS\n %s \nFIN\n", array);
		print_stacks(data);
		return (-1);
	}
	write(1, "C'est trié\n", 12);
	// print_stacks(data);
	free(data);
	return (0);
}
