/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:39:02 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/21 15:22:59 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Reverse Rotate a :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_rra(t_data *data, t_bool print_name)
{
	data->a = data->a->prev;
	if (print_name == 1)
		write(1, "rra\n", 4);
}

/**
 * @brief Reverse Rotate b :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_rrb(t_data *data, t_bool print_name)
{
	data->b = data->b->prev;
	if (print_name == 1)
		write(1, "rrb\n", 4);
}

/**
 * @brief Reverse Rotate a and b :
 * Executes Reverse Rotate a and Reverse Rotate b.
 *
 * @param data structure that handles the stacks
 * @param print_name set to 1 to print it's name
 */
void	ft_rrr(t_data *data, t_bool print_name)
{
	ft_rra(data, 0);
	ft_rrb(data, 0);
	if (print_name == 1)
		write(1, "rrr\n", 4);
}
