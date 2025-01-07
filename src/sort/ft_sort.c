/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:32 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/07 11:30:55 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	rotate_accordingly(t_data *data, int value_found, size_t cost);

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
		if (ft_sort_hardcoded(data) != 0)
			return (-1);
	if (data->a_len >= 5)
		sort_insertion(data);
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

static void	rotate_accordingly(t_data *data, int value_found, size_t cost)
{
	if (cost < data->a_len / 2)
		while (data->a->value != value_found)
			ft_ra(data, 1);
	else
		while (data->a->value != value_found)
			ft_rra(data, 1);
}

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
