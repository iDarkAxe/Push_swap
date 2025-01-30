/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:06:28 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/30 15:55:17 by ppontet          ###   ########lyon.fr   */
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
		if (data->a_len >= 1 \
			&& verify_duplicates(value, data->a, data->a_len) == -1)
			return (-3);
		temp = ft_stacknew(value);
		if (temp == NULL)
			return (-4);
		data->a_len++;
		ft_stackadd_back(&(data->a), temp, data->a_len);
	}
	return (0);
}

/**
 * @brief Parse the given args,
 * creates nodes and links them to make a stack
 * Uses _single_string for each argument so that it can handle multiple args
 * "151 1 2 3 4 5" 6 7 8 "9 10" 95 are valid arguments (args + strings).
 *
 * @param argc number of args
 * @param argv array of strings
 * @param data structure that handles the stacks
 * @return int 0 if OK, !0 is error
 */
int	fill_stack(int argc, char **argv, t_data *data)
{
	int	argc_temp;
	int	ret;

	argc_temp = 1;
	while (argc_temp < argc)
	{
		ret = fill_stack_single_string(argv[argc_temp], data);
		if (ret != 0)
			return (ret);
		argc_temp++;
	}
	return (0);
}
