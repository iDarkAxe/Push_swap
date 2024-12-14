/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:08:30 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 14:56:31 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

#ifndef DEBUG
# define DEBUG 0
# endif

# include <stddef.h> 

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	size_t 	a_len;
	size_t	b_len;
}	t_data;


// Stack related functions
t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);

// INSTRUCTIONS
void	ft_sa(t_data *data);
void	ft_sb(t_data *data);
void	ft_ss(t_data *data);

void	ft_pa(t_data *data);
void	ft_pb(t_data *data);

void	ft_ra(t_data *data);
void	ft_rb(t_data *data);
void	ft_rr(t_data *data);

void	ft_rra(t_data *data);
void	ft_rrb(t_data *data);
void	ft_rrr(t_data *data);

// FACULTATIF
int		remplissage_stack_tab(t_stack **stack);
void	print_stack(t_stack **stack);

#endif