/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:06:36 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 14:38:39 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_ra(t_data *data)
{
	t_stack *temp;

	temp = data->a;
	data->a = data->a->next;
	ft_stacklast(data->a)->next = temp;
	temp->next = NULL;
}

void ft_rb(t_data *data)
{
	t_stack *temp;

	temp = data->b;
	data->b = data->b->next;
	ft_stacklast(data->b)->next = temp;
	temp->next = NULL;
}

void ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
}
