/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:39:02 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/20 15:15:37 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

/**
 * @brief Reverse Rotate a :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 */
void	ft_rra(t_data *data)
{
	t_stack	*temp;
	t_stack	*previous_head;
	t_stack	*previous;

	temp = data->a;
	previous = NULL;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->a;
	data->a = temp;
	data->a->next = previous_head;
	write(1, "rra\n", 4);
}

// void	ft_rra(t_data *data)
// {
// 	t_stack	*temp;
// 	t_stack	*previous;

// 	// Vérifier si la pile est vide ou contient un seul élément
// 	if (data->a == NULL || data->a->next == NULL)
// 		return ;
// 	temp = data->a;
// 	previous = NULL;
// 	// Parcourir jusqu'au dernier élément
// 	while (temp->next != NULL)
// 	{
// 		previous = temp;
// 		temp = temp->next;
// 	}
// 	// Mise à jour des liens pour effectuer la rotation inversée
// 	previous->next = NULL;
// 	temp->next = data->a;
// 	data->a = temp;
// 	// Afficher l'opération
// 	write(1, "rra\n", 4);
// }

/**
 * @brief Reverse Rotate b :
 * Shifts all the stack down
 * and the last becomes first.
 *
 * @param data structure that handles the stacks
 */
void	ft_rrb(t_data *data)
{
	t_stack	*temp;
	t_stack	*previous_head;
	t_stack	*previous;

	temp = data->b;
	previous = NULL;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->b;
	data->b = temp;
	data->b->next = previous_head;
	write(1, "rrb\n", 4);
}

/**
 * @brief Reverse Rotate a and b :
 * Executes Reverse Rotate a and Reverse Rotate b.
 *
 * @param data structure that handles the stacks
 */
void	ft_rrr(t_data *data)
{
	t_stack	*temp;
	t_stack	*previous_head;
	t_stack	*previous;

	temp = data->a;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->a;
	data->a = temp;
	data->a->next = previous_head;
	temp = data->b;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	previous_head = data->b;
	data->b = temp;
	data->b->next = previous_head;
	write(1, "rrr\n", 4);
}
