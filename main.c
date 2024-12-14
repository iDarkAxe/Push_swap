/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:39:03 by ppontet           #+#    #+#             */
/*   Updated: 2024/12/14 13:41:40 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include <stdlib.h>
// @TODO REMOVE
#include <stdio.h>

void	print_stack(t_stack **stack);
int	remplissage_stack(int argc, char **argv, t_data *stack);

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc == 1)
		return (-1);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	if (DEBUG == 1)
		print_stack(&data->a);
	if (remplissage_stack(argc, argv, data) == -1)
		return (-1);
	if (DEBUG == 1)
		print_stack(&data->a);
	ft_sa(data);
	printf("\nAU SECOURS\n\n");
	if (DEBUG == 1)
		print_stack(&data->a);
}

void	print_stack(t_stack **stack)
{
	t_stack	*index;
	size_t	number;

	number = 0;
	index = *stack;
	while (index != NULL)
	{
		printf("stack[%ld] = %d\n", number++, index->value);
		index = index->next;
	}
}

/**
 * @brief Convert string to int, and handle number
 *
 * @param nptr
 * @return int
 */
int	ft_atoi(const char *nptr)
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

	while (argc > 1)
	{
		value = ft_atoi(argv[argc - 1]);
		temp = ft_stacknew(value);
		if (temp == NULL)
			return (free(data), -1);
		ft_stackadd_front(&(data->a), temp);
		argc--;
	}
	return (0);
}

int	verify_argument(char *str)
{
	(void)str;
	return (0);
}
