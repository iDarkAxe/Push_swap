/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_nbr_decroissant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:51:09 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/08 15:02:43 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// MIN and MAX are defined by default
#ifndef MIN
# define MIN -100
#endif

#ifndef MAX
# define MAX 100
#endif

// NBR of iterations, overrided by MAX and MIN
#ifndef NBR
# define NBR (MAX - MIN)
#endif

/**
 * @brief Print to stdout NBR of numbers from MIN to MAX
 * 
 * @return int 0, OK
 */
int	main(void)
{
	int		n;
	size_t	i;

	n = MIN;
	i = 0;
	while (n < MAX && i++ < NBR)
		printf("%d ", n++);
	return (0);
}
