/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:28:37 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/28 14:33:33 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_print.h"
#include <stddef.h>
#include <unistd.h>

#include <stdlib.h>

/**
 * @brief Print the stack
 * 
 * @param stack stack to print
 * @param len number of elements to print
 */
void	print_stack(t_stack *stack, size_t len, int fd)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = stack;
	while (index != NULL && number < len)
	{
		write(fd, "stack[", 6);
		ft_putnbr_fd((long long)number++, fd);
		write(fd, "] = ", 4);
		ft_putnbr_fd(index->value, fd);
		write(fd, "\n", 1);
		write(fd, "adress is [", 11);
		ft_putpointer_fd((unsigned long)index);
		write(fd, "]\n", 2);
		index = index->next;
	}
}

/**
 * @brief Print the stacks
 * 
 * @param data structure that handles the stacks
 * @param fd file descriptor
 */
void	print_stacks(t_data *data, int fd)
{
	if (data == NULL)
	{
		write(fd, "data is NULL\n", 13);
		return ;
	}
	write(fd, "a :\n", 4);
	if (data->a == NULL)
		write(fd, "Stack A is NULL\n", 16);
	else
		print_stack(data->a, data->a_len, fd);
	write(fd, "b :\n", 4);
	if (data->b == NULL)
		write(fd, "Stack B is NULL\n", 16);
	else
		print_stack(data->b, data->b_len, fd);
}

/**
 * @brief
 * Fills stacks with the values passed as arguments in stack A and stack B 
 * @deprecated Should be removed, conserved for templates
 * @param argc number of argument
 * @param argv array of string
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
__attribute__((deprecated))
int	fill_stacks(int argc, char **argv, t_data *data)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		value;

	data->a_len = 0;
	data->b_len = 0;
	while (argc > 1)
	{
		value = atoi(argv[argc - 1]);
		temp_a = ft_stacknew(value);
		if (temp_a == NULL)
			return ((void)ft_stackclear(data), -1);
		data->a_len++;
		temp_b = ft_stacknew(value);
		ft_stackadd_front(&(data->a), temp_a);
		if (temp_b == NULL)
			return ((void)ft_stackclear(data), -1);
		data->b_len++;
		ft_stackadd_front(&(data->b), temp_b);
		argc--;
	}
	return (0);
}

/**
 * @brief Print the stack
 * 
 * @param stack stack to print
 * @param len number of elements to print
 * @param fd file descriptor
 */
void	print_index(t_stack *stack, size_t len, int fd)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = stack;
	while (index != NULL && number < len)
	{
		write(1, "stack[", 6);
		ft_putnbr_fd((long long)number++, fd);
		write(fd, "] = ", 4);
		ft_putnbr_fd(index->value, fd);
		write(fd, "\n", 1);
		ft_putnbr_fd((long long)index->index, fd);
		write(fd, " is index\n", 11);
		index = index->next;
	}
}
