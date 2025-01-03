/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:32:03 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/03 20:34:12 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

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
