/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:39:02 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 15:14:06 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Reverse Rotate a :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 */
void	ft_rra(t_data *data)
{
	t_stack	*temp;
	t_stack	*previous_head;
	t_stack	*previous;

	temp = data->a;
	previous = NULL;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->a;
	data->a = temp;
	data->a->next = previous_head;
}

/**
 * @brief Reverse Rotate b :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 */
void	ft_rrb(t_data *data)
{
	t_stack	*temp;
	t_stack	*previous_head;
	t_stack	*previous;

	temp = data->b;
	previous = NULL;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->b;
	data->b = temp;
	data->b->next = previous_head;
}

/**
 * @brief Reverse Rotate a and b :
 * Executes Reverse Rotate a and Reverse Rotate b.
 *
 * @param data structure that handles the stacks
 */
void	ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
}
