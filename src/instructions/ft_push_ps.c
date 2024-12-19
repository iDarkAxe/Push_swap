/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:54:16 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/18 18:36:46 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Push a :
 * Takes the first element of b and put it on top of stack a.
 * Do nothing if b doesn't exit.
 *
 * @param data structure that handles the stacks
 */
void	ft_pa(t_data *data)
{
	t_stack	*temp;

	if (data->b == NULL)
		return ;
	temp = data->b;
	data->b = data->b->next;
	temp->next = NULL;
	ft_stackadd_front(&data->a, temp);
}

/**
 * @brief Push b :
 * Takes the first element of a and put it on top of stack b.
 * Do nothing if b doesn't exit.
 *
 * @param data structure that handles the stacks
 */
void	ft_pb(t_data *data)
{
	t_stack	*temp;

	if (data->a == NULL)
		return ;
	temp = data->a;
	data->a = data->a->next;
	temp->next = NULL;
	ft_stackadd_front(&data->b, temp);
}
