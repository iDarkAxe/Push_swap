/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:28:37 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/28 23:11:32 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stddef.h>
#include <stdlib.h>
// DONT FORGET TO REMOVE
#include <stdio.h>

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
	while (index != NULL && number < len + 1)
	{
		printf("stack[%zu] = %d\n", number++, index->value);
		printf("adress is[%p]\n", (void *)index);
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
		printf("data is NULL\n");
		return ;
	}
	printf("a :\n");
	if (data->a == NULL)
		printf("Stack A is NULL\n");
	else
		print_stack(data->a, data->a_len);
	printf("b :\n");
	if (data->b == NULL)
		printf("Stack B is NULL\n");
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
