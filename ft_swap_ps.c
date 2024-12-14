/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:49:53 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 14:13:09 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_pushswap.h"

void	ft_sa(t_data *data)
{
	int 	temp_value;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	temp_value = (data->a)->value;
	(data->a)->value = (data->a)->next->value;
	(data->a)->next->value = temp_value;
}

void	ft_sb(t_data *data)
{
	int 	temp_value;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	temp_value = (data->b)->value;
	(data->b)->value = (data->b)->next->value;
	(data->b)->next->value = temp_value;
}

void ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
}
