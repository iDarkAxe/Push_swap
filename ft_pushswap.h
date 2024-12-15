/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:08:30 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 16:09:16 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stddef.h> 

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}	t_stack;

typedef struct s_data
{
	size_t	a_len;
	size_t	b_len;
	t_stack	*a;
	t_stack	*b;
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

// OPTIONAL
int		remplissage_stack(int argc, char **argv, t_data *data);
void	print_stack(t_stack **stack);
// Adds OF OPTIONAL
void	print_stacks(t_data *data);
int		remplissage_stacks(int argc, char **argv, t_data *data);

#endif
