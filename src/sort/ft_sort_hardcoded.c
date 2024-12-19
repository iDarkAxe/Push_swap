/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hardcoded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:19 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/19 09:44:10 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdio.h>

static int	ft_sort_three(t_data *data);

/**
 * @brief Executes hard coded functions to sort stack with custom lengths
 *
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
int	ft_sort_hardcoded(t_data *data)
{
	if (data->a_len == 1)
		return (0);
	if (data->a_len == 2)
	{
		if (data->a->value > data->a->next->value)
			ft_sa(data);
		return (0);
	}
	if (data->a_len == 3)
		return (ft_sort_three(data));
	// if (data->a_len == 3 && data->a->value > data->a->next->value)
	// {
	// 	ft_sa(data);
	// 	printf("etat 1\n");
	// 	print_stacks(data);
	// 	if (data->a->value > data->a->next->next->value)
	// 	{
	// 		ft_ra(data);
	// 		printf("etat 2\n");
	// 		print_stacks(data);
	// 	}
	// 	if (data->a->next->value > data->a->next->next->value)
	// 	{
	// 		printf("etat 3\n");
	// 		ft_pb(data);
	// 		ft_sa(data);
	// 		ft_pa(data);
	// 		ft_ra(data);
	// 	}
	// 	printf("etat fin\n");
	// 	return (0);
	// }
	return (0);
}

/**
 * @brief Sort algorithm for 3 numbers
 *
 * @param data structure that handles the stacks
 * @return int 0, OK, -1 error
 */
static int	ft_sort_three(t_data *data)
{
	print_stacks(data);
	if (is_sorted(data) == 0)
		return (0);
	if (data->a->value > data->a->next->value
		&& data->a->next->next->value > data->a->next->value)
	{
		ft_ra(data);
		return (0);
	}
	if (data->a->value > data->a->next->value
		|| (data->a->next->value > data->a->next->next->value
			&& data->a->value < data->a->next->next->value))
		ft_sa(data);
	if (is_sorted(data) == 0)
		return (0);
	ft_ra(data);
	if (is_sorted(data) == 0)
		return (0);
	ft_sa(data);
	print_stacks(data);
	return (0);
}
