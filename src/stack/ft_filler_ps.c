/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:06:28 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/21 11:09:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>

/**
 * @brief Convert string to int, and handle number
 * (compliant to real atoi)
 *
 * @param nptr pointer to the start of the string
 * @return int value that was calculated
 */
static int	ft_atoi(const char *nptr)
{
	int			number;
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
		number = number * 10 + *nptr++ - '0';
		if (number == 214748364 && *nptr == '8')
			return (-2147483648);
	}
	if (minus_sign == -1)
		return ((int)-number);
	return ((int)number);
}

/**
 * @brief Verify if a single character is unauthorized
 *
 * @param letter character tested
 * @return char letter if authorized, 0 if not
 */
static char	verify_char(char letter)
{
	if ((letter >= '0' && letter <= '9') || letter == ' ' || letter == '-'
		|| letter == '+')
		return (letter);
	return (0);
}

/**
 * @brief Verify is there are unauthorized characters in arguments
 *
 * @param argc number of args
 * @param argv array of strings
 * @return int 0 if OK, -1 is error
 */
static int	verify_arguments(int argc, char **argv)
{
	size_t	index;
	int		arg_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		index = 0;
		while (argv[arg_index][index] != '\0')
		{
			if (verify_char(argv[arg_index][index]) == 0)
				return (-1);
			index++;
		}
		arg_index++;
	}
	return (0);
}

/**
 * @brief Parse the given args,
 * creates nodes and links them to make a stack
 * MOD of fill_stack to handle single string argument
 *
 * @param str single string that have multiple args
 * @param data structure that handles the stacks
 * @return int 0 if OK, !0 is error
 */
static int	fill_stack_single_string(char *str, t_data *data)
{
	t_stack	*temp;
	int		value;

	while (str != NULL && *str != '\0')
	{
		while (*str == ' ')
			str++;
		value = ft_atoi(str);
		if (value != ft_atol(str))
			return (-1);
		while (((*str >= '0' && *str <= '9') || *str == '-') && *str != ' ')
			str++;
		while (*str == ' ')
			str++;
		temp = ft_stacknew(value);
		if (temp == NULL \
			|| verify_duplicates(value, data->a, data->a_len) == -1)
			return (-4);
		data->a_len++;
		ft_stackadd_back(&(data->a), temp, data->a_len);
	}
	return (0);
}

/**
 * @brief Parse the given args,
 * creates nodes and links them to make a stack
 * Uses _single_string if number of args is 2
 *
 * @param argc number of args
 * @param argv array of strings
 * @param data structure that handles the stacks
 * @return int 0 if OK, !0 is error
 */
int	fill_stack(int argc, char **argv, t_data *data)
{
	t_stack	*temp;
	int		value;

	if (verify_arguments(argc, argv) == -1)
		return (-1);
	if (argc == 2)
		return (fill_stack_single_string(argv[1], data));
	while (argc > 1)
	{
		value = ft_atoi(argv[argc - 1]);
		if (value != ft_atol(argv[argc - 1]))
			return (-2);
		if (data->a_len >= 1 \
			&& verify_duplicates(value, data->a, data->a_len) == -1)
			return (-3);
		temp = ft_stacknew(value);
		if (temp == NULL)
			return (-4);
		data->a_len++;
		ft_stackadd_front(&(data->a), temp);
		argc--;
	}
	return (0);
}
