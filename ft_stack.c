/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:58:40 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 15:04:18 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

/**
 * @brief Alloue (avec malloc(3)) et renvoie un nouvel élément. 
 * La variable ’content’ est initialisée à l’aide de la valeur 
 * du paramètre ’content’. La variable ’next’ est initialisée à NULL.
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
 * @brief Ajoute l’élément ’new’ au début de la stack.
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
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
