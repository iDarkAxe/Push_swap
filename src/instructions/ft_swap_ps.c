/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:49:53 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/21 15:23:04 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Swap a :
 * Swaps the first and second element in a
 * Do nothing if first or second doesn't exist
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_sa(t_data *data, t_bool print_name)
{
	int	temp_value;

	if (data->a == NULL || data->a->next == NULL)
		return ;
	temp_value = (data->a)->value;
	(data->a)->value = (data->a)->next->value;
	(data->a)->next->value = temp_value;
	if (print_name == 1)
		write(1, "sa\n", 3);
}

/**
 * @brief Swap b :
 * Swaps the first and second element in b
 * Do nothing if first or second doesn't exist
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_sb(t_data *data, t_bool print_name)
{
	int	temp_value;

	if (data->b == NULL || data->b->next == NULL)
		return ;
	temp_value = (data->b)->value;
	(data->b)->value = (data->b)->next->value;
	(data->b)->next->value = temp_value;
	if (print_name == 1)
		write(1, "sb\n", 3);
}

/**
 * @brief Swap S :
 * Executes Swap A and B
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_ss(t_data *data, t_bool print_name)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	if (print_name == 1)
		write(1, "ss\n", 3);
}
