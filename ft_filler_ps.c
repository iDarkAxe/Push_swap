/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:06:28 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 18:11:16 by ppontet          ###   ########lyon.fr   */
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
	if ((letter >= '0' && letter <= '9') || letter == ' ' || letter == '-')
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
 * @return int 0 if OK, -1 is error
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
		while (((*str >= '0' && *str <= '9') || *str == '-') && *str != ' ')
			str++;
		while (*str == ' ')
			str++;
		temp = ft_stacknew(value);
		if (temp == NULL)
			return ((void)free(data), -1);
		data->a_len++;
		ft_stackadd_back(&(data->a), temp);
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
 * @return int 0 if OK, -1 is error
 */
int	fill_stack(int argc, char **argv, t_data *data)
{
	t_stack	*temp;
	int		value;

	data->a_len = 0;
	if (verify_arguments(argc, argv) == -1)
		return (-1);
	if (argc == 2)
		return (fill_stack_single_string(argv[1], data));
	while (argc > 1)
	{
		value = ft_atoi(argv[argc - 1]);
		temp = ft_stacknew(value);
		if (temp == NULL)
			return ((void)free(data), -1);
		data->a_len++;
		ft_stackadd_front(&(data->a), temp);
		argc--;
	}
	return (0);
}
