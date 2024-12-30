/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:28:37 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/30 17:56:13 by ppontet          ###   ########lyon.fr   */
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
void	print_stack(t_stack *stack, size_t len)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = stack;
	while (index != NULL && number < len)
	{
		write(1, "stack[", 6);
		ft_putnbr_fd((long long)number++, 1);
		write(1, "] = ", 4);
		ft_putnbr_fd(index->value, 1);
		write(1, "\n", 1);
		write(1, "adress is [", 11);
		ft_putpointer_fd((unsigned long)index);
		write(1, "]\n", 2);
		index = index->next;
	}
}

/**
 * @brief Print the stacks
 * 
 * @param data structure that handles the stacks
 */
void	print_stacks(t_data *data)
{
	if (data == NULL)
	{
		write(1, "data is NULL\n", 13);
		return ;
	}
	write(1, "a :\n", 4);
	if (data->a == NULL)
		write(1, "Stack A is NULL\n", 16);
	else
		print_stack(data->a, data->a_len);
	write(1, "b :\n", 4);
	if (data->b == NULL)
		write(1, "Stack B is NULL\n", 16);
	else
		print_stack(data->b, data->b_len);
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
