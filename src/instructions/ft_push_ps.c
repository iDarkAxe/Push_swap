/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:54:16 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/08 14:35:05 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Push a :
 * Takes the first element of b and put it on top of stack a.
 * Do nothing if b doesn't exit.
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_pa(t_data *data, t_bool print_name)
{
	t_stack	*temp;

	if (data->b == NULL)
		return ;
	temp = data->b;
	data->b->next->prev = data->b->prev;
	data->b->prev->next = data->b->next;
	data->b = data->b->next;
	temp->next = NULL;
	temp->prev = NULL;
	ft_stackadd_front(&data->a, temp);
	data->b_len--;
	data->a_len++;
	if (data->b_len == 0)
		data->b = NULL;
	if (print_name == 1)
		write(1, "pa\n", 3);
}

/**
 * @brief Push b :
 * Takes the first element of a and put it on top of stack b.
 * Do nothing if b doesn't exit.
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_pb(t_data *data, t_bool print_name)
{
	t_stack	*temp;

	if (data->a == NULL)
		return ;
	temp = data->a;
	data->a->next->prev = data->a->prev;
	data->a->prev->next = data->a->next;
	data->a = data->a->next;
	temp->next = NULL;
	temp->prev = NULL;
	ft_stackadd_front(&data->b, temp);
	data->a_len--;
	data->b_len++;
	if (data->a_len == 0)
		data->a = NULL;
	if (print_name == 1)
		write(1, "pb\n", 3);
}
