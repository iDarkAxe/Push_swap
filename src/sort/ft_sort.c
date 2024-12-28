/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:32 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/29 00:08:58 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			sort_smart(t_data *data);
static void	sort_b_stack(t_data *data);

/**
 * @brief Function used to call other sort algorithms
 *
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
int	ft_sort(t_data *data)
{
	if (data->a_len < 5)
		if (ft_sort_hardcoded(data) != 0)
			return (-1);
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

/**
 * @brief Sort the stack with a smart algorithm
 * @todo : Implement a better algorithm
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
int	sort_smart(t_data *data)
{
	while (is_sorted(data) != 0)
	{
		print_stacks(data);
		if (data->a->value < data->a->next->value && \
			data->a->value < data->a->next->next->value)
			ft_pb(data, 1);
		else if (data->a->value < data->a->next->next->value && \
					data->a->next->value > data->a->next->next->value)
		{
			ft_rra(data, 1);
			ft_pb(data, 1);
		}
		else if (data->a->next->value < data->a->value && \
					data->a->next->value < data->a->next->next->value)
		{
			ft_sa(data, 1);
			ft_pb(data, 1);
		}
		sort_b_stack(data);
	}
	return (0);
}

/**
 * @brief Sort the stack b
 *
 * @param data structure that handles the stacks
 */
static void	sort_b_stack(t_data *data)
{
	while (data->b_len > 2 && data->b->value > data->b->next->value)
		ft_rb(data, 1);
}
