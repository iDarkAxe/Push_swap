/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:33:07 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/22 10:49:41 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int	count_max_bitsz(t_stack **stack, size_t len);

void	sort_radix(t_data *data)
{
	int		i;
	size_t	j;
	size_t	size;
	int		max_bits;

	i = 0;
	size = data->a_len;
	max_bits = count_max_bits(&data->a, data->a_len);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((data->a->value >> i) & 1) == 1)
				ft_ra(data, 1);
			else
				ft_pb(data, 1);
		}
		while (data->b_len > 0)
			ft_pa(data, 1);
		i++;
	}
}

static int	count_max_bits(t_stack **stack, size_t len)
{
	t_stack	*head;
	size_t	count;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->value;
	max_bits = 0;
	count = 0;
	while (head && count < len)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
		count++;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
