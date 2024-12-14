/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_only.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:28:37 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 14:56:26 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stddef.h>

void	print_stack(t_stack **stack)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = *stack;
	while (index != NULL)
	{
		printf("stack[%ld] = %d\n", number++, index->value);
		index = index->next;
	}
}

// int		tab[10] = {10, 85, 45, 98, -52, 789, 352, 10, 15, 8294};
int	remplissage_stack_tab(t_stack **stack)
{
	ssize_t	index;
	t_stack	*temp;
	int		tab[10];

	index = 0;
	while (index < 10)
		tab[index] = index;
	index = 10 - 1;
	while (index >= 0)
	{
		temp = ft_stacknew(tab[index]);
		if (temp == NULL)
			return (free(stack), -1);
		ft_stackadd_front(stack, temp);
		if (index == 0)
			break ;
		index--;
	}
	return (0);
}
