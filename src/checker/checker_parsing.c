/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:55:42 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/28 23:00:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_pushswap.h"
#include "get_next_line.h"

static size_t	ft_strlen(char *str);
static void		parse_and_execute_rotate(t_data *data, char *str);

/**
 * @brief Parse and executes associated functions
 * 
 * @param data structure that handles the stacks
 */
void	parse_and_execute(t_data *data)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (ft_strlen(str) < 3 || (*str != 'p' && *str != 's' && *str != 'r'))
			return ;
		if (*str == 'p' && *(str + 1) == 'a')
			ft_pa(data, PRINT_NAME);
		else if (*str == 'p' && *(str + 1) == 'b')
			ft_pb(data, PRINT_NAME);
		else if (*str == 's' && *(str + 1) == 'a')
			ft_sa(data, PRINT_NAME);
		else if (*str == 's' && *(str + 1) == 'b')
			ft_sb(data, PRINT_NAME);
		else
			parse_and_execute_rotate(data, str);
		free(str);
		str = get_next_line(0);
	}
	return ;
}

/**
 * @brief Second part of P&E that handles rotates and errors
 * 
 * @param data structure that handles the stacks
 * @param str string to search chars
 */
static void	parse_and_execute_rotate(t_data *data, char *str)
{
	if (*str == 'r' && *(str + 1) == 'a')
		ft_ra(data, PRINT_NAME);
	else if (*str == 'r' && *(str + 1) == 'b')
		ft_rb(data, PRINT_NAME);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == '\n')
		ft_rr(data, PRINT_NAME);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'r')
		ft_rrr(data, PRINT_NAME);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'a')
		ft_rra(data, PRINT_NAME);
	else if (*str == 'r' && *(str + 1) == 'r' && *(str + 2) == 'b')
		ft_rrb(data, PRINT_NAME);
	else
		write(2, "Instruction Not recognized\n", 27);
}

/**
 * @brief Simple strlen
 * 
 * @param str string to count char from
 * @return size_t number of character found
 */
static size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
