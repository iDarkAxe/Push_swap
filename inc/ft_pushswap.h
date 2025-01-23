/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:08:30 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/23 17:00:23 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

/**
 * @file ft_pushswap.h
 * @brief Header file for the pushswap project.
 *
 */

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stddef.h>
# include <unistd.h>

/**
 * @defgroup Types Data Types
 * @brief All the data types used in the project.
 * @{
 */

/**
 * @brief Boolean type
 */
typedef char		t_bool;

/**
 * @brief Stack structure, doubly linked list
 */
typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	size_t			index;
	int				value;
	t_bool			checked;
}					t_stack;

/**
 * @brief Data structure, contains the two stacks and their lengths
 */
typedef struct s_data
{
	size_t			a_len;
	size_t			b_len;
	t_stack			*a;
	t_stack			*b;
}					t_data;
/** @} */

/**
 * @defgroup Main Main functions
 * @brief Core functionnality of the project.
 * @{
 */

// Main function
int					ft_pushswap(int argc, char **argv);

// Error handling and stack initialization
int					errors_handler(int error, t_data *data);
int					init_data(t_data *data);
/** @} */

/**
 * @defgroup Stack Stack functions
 * @brief All the functions used to create a stack, and verify it's validity.
 * @{
 */

// Stack related functions
t_stack				*ft_stacknew(int content);
void				ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack				*ft_stacklast(t_stack *stack, size_t stack_len);
void				ft_stackadd_back(t_stack **stack, t_stack *new,
						size_t stack_len);
int					ft_stackclear(t_data *data);

// Filling stack related functions
int					fill_stack(int argc, char **argv, t_data *data);

// Verify related functions
int					verify_duplicates(int value, t_stack *data,
						size_t stack_len);
long				ft_atol(const char *nptr);
/** @} */

/**
 * @defgroup Sorting Sorting functions
 * @brief All the sorting functions used.
 * @{
 */

// Sort related functions
int					is_sorted(t_data *data);
int					ft_sort(t_data *data);
int					ft_sort_hardcoded(t_data *data);

// Sort Algorithms
void				sort_insertion(t_data *data);
void				sort_radix(t_data *data);

// Cost related functions
int					find_value(t_stack *stack, size_t len, t_bool max_selected);
int					find_nearest(t_stack *stack, size_t len, int *value_found,
						size_t *cost);
size_t				cost_calculator(t_stack *stack, size_t len, int value);
void				build_index(t_data *data);
/** @} */

/**
 * @defgroup Instructions Instructions
 * @brief All the different instructions authorized.
 * @{
 */
void				ft_sa(t_data *data, t_bool print_name);
void				ft_sb(t_data *data, t_bool print_name);
void				ft_ss(t_data *data, t_bool print_name);

void				ft_pa(t_data *data, t_bool print_name);
void				ft_pb(t_data *data, t_bool print_name);

void				ft_ra(t_data *data, t_bool print_name);
void				ft_rb(t_data *data, t_bool print_name);
void				ft_rr(t_data *data, t_bool print_name);

void				ft_rra(t_data *data, t_bool print_name);
void				ft_rrb(t_data *data, t_bool print_name);
void				ft_rrr(t_data *data, t_bool print_name);
/** @} */

/**
 * @defgroup Optional Optional functions for debugging
 * @brief Optional functions used to understand
 * what is happening when something goes wrong.
 * @{
 */

void				print_stack(t_stack *stack, size_t len);
void				print_index(t_stack *stack, size_t len);

// Adds OF OPTIONAL
void				print_stacks(t_data *data);
int					fill_stacks(int argc, char **argv, t_data *data);
/** @} */

#endif
