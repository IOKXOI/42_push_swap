/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/11 10:32:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

int	ft_argv_count(const char *str)
{
	size_t argv_count;

	argv_count = 0;

	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '+' || *str == '-')
				str++;
		if (*str >= '0' && *str <= '9')
		{
			argv_count++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
	}
	return (argv_count);
}
#include <stdio.h>

int	check_duplicate(int *input, int size)
{
	int	i;
	int	j;

	i = 0;
	printf("size = %d\n\n", size);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			printf("i = %d\nj = %d\n\n\n", i, j);
			if (input[i] == input[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
