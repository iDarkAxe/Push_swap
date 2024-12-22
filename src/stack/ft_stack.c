/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:58:40 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 17:29:52 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

/**
 * @brief Allocates and returns the newly created element
 * 'value' is initialised with content
 * 'next' is set to NULL
 * 
 * @param content value to add when creating the element
 * @return tstack* pointer to the element
 */
t_stack	*ft_stacknew(int content)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (element == NULL)
		return (NULL);
	element->value = content;
	element->next = NULL;
	return (element);
}

/**
 * @brief Adds the 'new' element at the start of stack
 * 
 * @param stack head of stack
 * @param new element to add
 */
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack *handler;

	handler = stack;
	while (stack != NULL)
	{
		handler = stack;
		stack = stack->next;
	}
	return (handler);
}

/**
 * @brief Adds the 'new' element at the end of stack
 * 
 * @param stack head of stack
 * @param new element to add
 */
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL || new == NULL)
		return ;
	last = ft_stacklast(*stack);
	if (last == NULL)
		*stack = new;
	else
		last->next = new;
}

/**
 * @brief Supprime et libère la mémoire de l’élément passé en paramètre, 
 * et de tous les éléments qui suivent, à l’aide de ’del’ et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL.
 * 
 * @param data structure that handles the stacks
 */
void	ft_stackclear(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*temp_a;
	t_stack	*stack_b;
	t_stack	*temp_b;

	if (data == NULL)
		return ;
	stack_a = data->a;
	while (stack_a != NULL)
	{
		temp_a = stack_a;
		stack_a = stack_a->next;
		free(temp_a);
	}
	stack_b = data->b;
	while (stack_b != NULL)
	{
		temp_b = stack_b;
		stack_b = stack_b->next;
		free(temp_b);
	}
	free(data);
}
