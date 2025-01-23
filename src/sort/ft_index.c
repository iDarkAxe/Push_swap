/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:14:44 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/23 16:59:38 by ppontet          ###   ########lyon.fr   */
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
static int	find_value_index(t_stack *stack, size_t len)
{
	size_t	count;
	t_stack	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL && len > 0)
	{
		if (temp->value < stack->value)
			count++;
		temp = temp->next;
		len--;
	}
	return (count);
}

void	build_index(t_data *data)
{
	size_t	i;
	t_stack	*temp;

	i = 0;
	temp = data->a;
	while (temp != NULL && i < data->a_len)
	{
		temp->index = find_value_index(temp, data->a_len);
		temp = temp->next;
		i++;
	}
}
