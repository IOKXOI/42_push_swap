/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/06/06 13:54:14 by sydauria         ###   ########.fr       */
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

int	check_duplicate(int *input, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size) // check 0 1 2 3 0
	{
		j = i + 1;
		while (j < size)
		{
			if (input[i] == input[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
