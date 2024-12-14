/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:54:16 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 14:05:31 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_pa(t_data *data)
{
	t_stack *temp;

	if (data->b == NULL)
		return ;
	temp = data->b;
	data->b = data->b->next;
	temp->next = NULL;
	ft_stackadd_front(&data->a, temp);
}

void ft_pb(t_data *data)
{
	t_stack *temp;

	if (data->a == NULL)
		return ;
	temp = data->a;
	data->a = data->a->next;
	temp->next = NULL;
	ft_stackadd_front(&data->a, temp);
}
