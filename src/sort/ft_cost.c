/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:32:03 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/25 13:40:03 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Find the value in the stack,
 * the smallest (0) or the biggest (1)
 * 
 * @param stack stack to search
 * @param len length of the stack
 * @param max_selected 0 for smallest, 1 for biggest
 * @return int value found
 */
int	find_value(t_stack *stack, size_t len, t_bool max_selected)
{
	size_t	i;
	int		value;
	t_stack	*temp;

	i = 0;
	value = stack->value;
	temp = stack;
	while (temp != NULL && i < len)
	{
		if (max_selected == 1 && temp->value > value)
			value = temp->value;
		else if (max_selected == 0 && temp->value < value)
			value = temp->value;
		temp = temp->next;
		i++;
	}
	return (value);
}

/**
 * @brief Find the nearest value and the cost to reach it
 * 
 * @param stack stack to search
 * @param len length of the stack
 * @param value_found value found
 * @param cost cost to reach the value
 * @return int 0 for smallest, 1 for biggest
 */
int	find_nearest(t_stack *stack, size_t len, int *value_found,
		size_t *cost)
{
	int		min;
	int		max;
	size_t	min_cost;
	size_t	max_cost;

	min = find_value(stack, len, 0);
	max = find_value(stack, len, 1);
	min_cost = cost_calculator(stack, len, min);
	max_cost = cost_calculator(stack, len, max);
	if (min_cost <= max_cost)
	{
		*value_found = min;
		*cost = min_cost;
		return (0);
	}
	else
	{
		*value_found = max;
		*cost = max_cost;
		return (1);
	}
}

/**
 * @brief Calculate the cost to reach a value
 * 
 * @param stack stack to search
 * @param len length of the stack
 * @param value value to found
 * @return size_t number of steps to reach the value
 */
size_t	cost_calculator(t_stack *stack, size_t len, int value)
{
	size_t	cost;
	t_stack	*temp;

	cost = 0;
	temp = stack;
	while (temp->value != value && cost < len)
	{
		temp = temp->next;
		cost++;
	}
	return (cost);
}

void	rotate_accordingly(t_data *data, int value_found, size_t cost)
{
	if (cost < data->a_len / 2)
		while (data->a->value != value_found)
			ft_ra(data, 1);
	else
		while (data->a->value != value_found)
			ft_rra(data, 1);
}
