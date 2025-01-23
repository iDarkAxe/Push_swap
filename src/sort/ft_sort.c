/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:32 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/23 16:57:39 by ppontet          ###   ########lyon.fr   */
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
		if (ft_sort_hardcoded(data) != 0)
			return (-1);
	if (data->a_len >= 5 && data->a_len <= 10)
		sort_insertion(data);
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
