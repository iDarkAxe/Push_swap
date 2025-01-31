/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:03:00 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/31 09:27:15 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static t_bool	verify_after_digit(char current, char next);

/**
 * @brief Verify is there are unauthorized characters in arguments
 *
 * @param argc number of args
 * @param argv array of strings
 * @return int 0 if OK, -1 is error
 */
int	verify_arguments(int argc, char **argv)
{
	size_t	index;
	int		arg_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		index = 0;
		while (argv[arg_index][index] != '\0')
		{
			if (verify_after_digit(argv[arg_index][index], argv[arg_index][index
				+ 1]) == 0)
				return (-1);
			index++;
		}
		arg_index++;
	}
	return (0);
}

/**
 * @brief Check in the stack if a value is already in
 *
 * @param value value to find
 * @param stack	stack where to search
 * @return int 0, OK not found, -1 error
 */
int	verify_duplicates(int value, t_stack *stack, size_t stack_len)
{
	t_stack	*temp;
	size_t	len;

	temp = stack;
	len = 0;
	while (temp != NULL && len < stack_len)
	{
		if (value == temp->value)
			return (-1);
		temp = temp->next;
		len++;
	}
	return (0);
}

/**
 * @brief Convert string to long, and handle number
 *
 * @param nptr pointer to the start of the string
 * @return long value that was calculated
 */
long	ft_atol(const char *nptr)
{
	long		number;
	long		overflow_tester;
	short int	minus_sign;

	number = 0;
	minus_sign = 0;
	while (*nptr != '\0' && (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
			|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f'))
		nptr++;
	if (*nptr != '\0' && ((*nptr == '-') || (*nptr == '+')))
	{
		if (*nptr == '-')
			minus_sign = -1;
		nptr++;
	}
	while (*nptr != '\0' && *nptr >= '0' && *nptr <= '9')
	{
		overflow_tester = number;
		number = number * 10 + *nptr++ - '0';
		if (overflow_tester > number)
			return (-(!minus_sign));
	}
	if (minus_sign == -1)
		return (-number);
	return (number);
}

/**
 * @brief Verify if a character is authorized after a digit
 * Also verify if the digit is authorized
 * 
 * @param current First character
 * @param next Character following the first
 * @return t_bool 1 if OK, 0 if error 
 */
static t_bool	verify_after_digit(char current, char next)
{
	if (current >= '0' && current <= '9')
	{
		if (next == ' ' || next == '\0' || (next >= '0' && next <= '9'))
			return (1);
		return (0);
	}
	if (current == ' ')
	{
		if (next == ' ' || next == '\0' || next == '-' || next == '+'
			|| (next >= '0' && next <= '9'))
			return (1);
		return (0);
	}
	if (current == '-' || current == '+')
	{
		if (next >= '0' && next <= '9')
			return (1);
		return (0);
	}
	return (0);
}
