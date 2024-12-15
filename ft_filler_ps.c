/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:06:28 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/15 16:09:03 by ppontet          ###   ########lyon.fr   */
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

int	remplissage_stack(int argc, char **argv, t_data *data)
{
	t_stack	*temp;
	int		value;

	data->a_len = 0;
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
