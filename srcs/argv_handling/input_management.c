/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/11 17:39:05 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

/*
static int	ft_argv_count(const char *str)
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
}*/

void	is_already_sorted(int *input, t_repo *repo)
{
	int	i;
	int	its_increasing;
	
	i = 0;
	its_increasing = 1;
	while (i < repo->size - 1)
	{
		if (input[i] > input[i + 1])
			its_increasing++;
		i++;
	}
	if (its_increasing == repo->size)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}

void	check_duplicate(int *input, t_repo *repo)
{
	int	i;
	int	j;

	i = 0;
	while (i < repo->size - 1) // check 0 1 2 3 0
	{
		j = i + 1;
		while (j < repo->size)
		{
			if (input[i] == input[j])
			{
				free(input);
				write(2, "Error\n", 6);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
