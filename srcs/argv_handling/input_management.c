/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:14:15 by sydauria         ###   ########.fr       */
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
		if (input[i] < input[i + 1])
			its_increasing++;
		i++;
	}
	if (its_increasing == repo->size)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}

int	is_already_sorted_list(t_repo *repo)
{
	int		check;
	int		loop;
	t_stack	*stack_a;

	loop = 1;
	stack_a = repo->stack_a_first;
	check = stack_a->value;
	if (stack_a->next)
		stack_a = stack_a->next;
	while (loop)
	{
		if (check < stack_a->value)
		{
			check = stack_a->value;
			stack_a = stack_a->next;
		}
		else if (check > stack_a->value)
			return (0);
		if (stack_a == repo->stack_a_last || !stack_a)
			loop = 0;
	}
	return (1);
}

void	check_duplicate(int *input, t_repo *repo)
{
	int	i;
	int	j;

	i = 0;
	while (i < repo->size - 1)
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
