/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:01:27 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/28 19:18:10 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "push_swap.h"

static int ft_multi_atoi(int *input, char *argv, int sign)
{
	size_t	nb;
	int		count;
	int		k;

	count = 0;
	k = 0;
	while (argv[k])
	{
		nb = 0;
		while (argv[k] == ' ' || (argv[k] >= 9 && argv[k] <= 13)
				|| argv[k] == '+' || argv[k] == '-')
		{
			if (argv[k] == '-')
				sign *= -1;
			k++;
		}
		while (argv[k] >= '0' && argv[k] <= '9')
		{
			nb = nb * 10 + (argv[k] - '0');
			k++;
		}
		if ((long long)nb * sign < INT_MIN || (long long)nb * sign > INT_MAX)
			return (-1);
		input[count] = sign * nb;
		sign = 1;
		count++;
	}
	return (count);
}

int	fill_input(int *input, char **argv)
{
	int	i;
	int	k;
	int	retrn;

	i = 0;
	k = 1;
	retrn = 0;
	while (argv[k])
	{
		retrn += ft_multi_atoi(input + i, *(argv + k), 1);
		if (retrn == -1)
			return (-1);
		k++;
		i+= retrn;
		retrn = 0;
	}
	return (0);
}

