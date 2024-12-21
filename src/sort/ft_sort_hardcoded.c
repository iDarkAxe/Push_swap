/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hardcoded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:24:19 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/21 15:34:41 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_sort.h"
#include <stdio.h>

static void	ft_sort_three(t_data *data);
static void	ft_sort_four(t_data *data);

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
	else if (data->a_len == 2 && data->a->value > data->a->next->value)
		ft_sa(data, 1);
	else if (data->a_len == 2)
		return (0);
	else if (data->a_len == 3)
		ft_sort_three(data);
	else if (data->a_len == 4)
		ft_sort_four(data);
	return (0);
}

/**
 * @brief Sort algorithm for 3 numbers
 *
 * @param data structure that handles the stacks
 */
static void	ft_sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bottom;

	top = data->a->value;
	mid = data->a->next->value;
	bottom = data->a->next->next->value;
	if (top > mid && mid > bottom)
	{
		ft_sa(data, 1);
		ft_rra(data, 1);
	}
	else if (top < mid && mid > bottom && bottom < top)
		ft_rra(data, 1);
	else if (top > mid && mid < bottom && bottom < top)
		ft_ra(data, 1);
	else if (top < mid && mid > bottom && bottom > top)
	{
		ft_sa(data, 1);
		ft_ra(data, 1);
	}
	else if (top > mid && mid < bottom && bottom > mid)
		ft_sa(data, 1);
	return ;
}

/**
 * @brief Sort algorithm for 4 numbers
 *
 * @param data structure that handles the stacks
 */
static void	ft_sort_four(t_data *data)
{
	t_sort_values	a;

	a.first = data->a->value;
	a.second = data->a->next->value;
	a.third = data->a->next->next->value;
	a.fourth = data->a->next->next->next->value;
	if (a.first < a.second && a.second < a.third && a.third < a.fourth)
		return ;
	if (a.second < a.first && a.second < a.third && a.second < a.fourth)
		ft_sa(data, 1);
	else if (a.third < a.first && a.third < a.second && a.third < a.fourth)
	{
		ft_ra(data, 1);
		ft_ra(data, 1);
	}
	else if (a.fourth < a.first && a.fourth < a.second && a.fourth < a.third)
		ft_rra(data, 1);
	ft_pb(data, 1);
	ft_sort_three(data);
	ft_pa(data, 1);
}
