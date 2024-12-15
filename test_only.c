/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:28:37 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 16:11:11 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stddef.h>
// DONT FORGET TO REMOVE
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_stack **stack)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = *stack;
	while (index != NULL)
	{
		printf("stack[%ld] = %d\n", number++, index->value);
		index = index->next;
	}
}

void	print_stacks(t_data *data)
{
	printf("a :\n");
	print_stack(&data->a);
	printf("b :\n");
	print_stack(&data->b);
}

int	remplissage_stacks(int argc, char **argv, t_data *data)
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
			return ((void)free(data), -1);
		data->a_len++;
		temp_b = ft_stacknew(value);
		ft_stackadd_front(&(data->a), temp_a);
		if (temp_b == NULL)
			return ((void)free(data), -1);
		data->b_len++;
		ft_stackadd_front(&(data->b), temp_b);
		argc--;
	}
	return (0);
}
