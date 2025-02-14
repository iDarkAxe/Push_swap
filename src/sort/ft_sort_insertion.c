/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:59 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/25 16:13:26 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	sort_insertion(t_data *data)
{
	int		value_found;
	size_t	cost;
	int		result;

	while (data->a_len > 0)
	{
		result = find_nearest(data->a, data->a_len, &value_found, &cost);
		rotate_accordingly(data, value_found, cost);
		ft_pb(data, 1);
		if (result == 1)
			ft_rb(data, 1);
	}
	while (data->b_len > 0 && data->b->value != \
		find_value(data->b, data->b_len, 1))
		ft_pa(data, 1);
	while (data->b_len > 0)
	{
		ft_rrb(data, 1);
		ft_pa(data, 1);
		ft_ra(data, 1);
	}
}
