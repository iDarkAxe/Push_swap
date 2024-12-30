/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:58:40 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/30 18:11:46 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

static int	ft_stackclear_b(t_data *data);

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
	element->prev = NULL;
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
	if (*stack != NULL && (*stack)->prev != NULL)
	{
		new->prev = (*stack)->prev;
		new->next = *stack;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	else
	{
		new->prev = new;
		new->next = new;
	}
	*stack = new;
}

/**
 * @brief Adds the 'new' element at the end of stack
 * 
 * @param stack head of stack
 * @param new element to add
 */
void	ft_stackadd_back(t_stack **stack, t_stack *new, size_t stack_len)
{
	t_stack	*last;
	t_stack	*stack_cpy;
	size_t	index;

	index = 0;
	if (stack == NULL || new == NULL)
		return ;
	last = NULL;
	stack_cpy = *stack;
	while (stack_cpy != NULL && index < stack_len - 1)
	{
		last = stack_cpy;
		stack_cpy = stack_cpy->next;
		index++;
	}
	if (last == NULL)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
	}
}

/**
 * @brief Remove all elements from stack a and b
 * 
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
int	ft_stackclear(t_data *data)
{
	t_stack	*temp_a;

	if (data == NULL)
		return (-1);
	if (data->a == NULL)
		return (ft_stackclear_b(data));
	if (data->a->prev != NULL)
		data->a->prev->next = NULL;
	while (data->a != NULL && data->a_len > 0)
	{
		temp_a = data->a;
		data->a = data->a->next;
		free(temp_a);
		data->a_len--;
	}
	ft_stackclear_b(data);
	free(data);
	data = NULL;
	return (0);
}

/**
 * @brief Remove all elements from stack b
 * 
 * @param data structure that handles the stacks
 * @return int 0 OK, -1 is error
 */
static int	ft_stackclear_b(t_data *data)
{
	t_stack	*temp_b;

	if (data->b == NULL)
		return (-1);
	if (data->b->prev != NULL)
		data->b->prev->next = NULL;
	while (data->b != NULL && data->b_len > 0)
	{
		temp_b = data->b;
		data->b = data->b->next;
		free(temp_b);
		data->b_len--;
	}
	return (0);
}
