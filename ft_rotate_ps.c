/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:06:36 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 15:08:52 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Rotate a :
 * Shifts all the stack up
 * and the first becomes last.
 *
 * @param data structure that handles the stacks
 */
void	ft_ra(t_data *data)
{
	t_stack	*temp;

	temp = data->a;
	data->a = data->a->next;
	ft_stacklast(data->a)->next = temp;
	temp->next = NULL;
}

/**
 * @brief Rotate b :
 * Shifts all the stack up
 * and the first becomes last.
 *
 * @param data structure that handles the stacks
 */
void	ft_rb(t_data *data)
{
	t_stack	*temp;

	temp = data->b;
	data->b = data->b->next;
	ft_stacklast(data->b)->next = temp;
	temp->next = NULL;
}

/**
 * @brief Rotate a and b :
 * Executes Rotate a and Rotate b.
 *
 * @param data structure that handles the stacks
 */
void	ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
}
