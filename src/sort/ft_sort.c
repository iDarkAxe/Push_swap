/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:32 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/25 15:32:51 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Function used to call other sort algorithms
 *
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
int	ft_sort(t_data *data)
{
	if (is_sorted(data) == 0)
		return (0);
	if (data->a_len < 5)
		ft_sort_hardcoded(data);
	if (data->a_len >= 5 && data->a_len <= 10)
		ft_sort_small(data);
	if (data->a_len > 10)
		sort_radix(data);
	return (is_sorted(data));
}

/**
 * @brief Verify if there is something in stack b,
 * and if stack a is sorted
 *
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
int	is_sorted(t_data *data)
{
	size_t	len;
	t_stack	*temp;

	if (data->b != NULL || data->b_len != 0)
		return (-1);
	temp = data->a;
	len = 0;
	while (len < data->a_len - 1 && temp != NULL && temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (-1);
		temp = temp->next;
		len++;
	}
	return (0);
}

void	ft_sort_small(t_data *data)
{
	int	value;

	while (data->a_len > 4)
	{
		value = find_value(data->a, data->a_len, 0);
		rotate_accordingly(data, value, cost_calculator(data->a, data->a_len,
				value));
		ft_pb(data, 1);
	}
	ft_sort_four(data);
	while (data->b_len > 0)
		ft_pa(data, 1);
}
