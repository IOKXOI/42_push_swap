/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:49:20 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:07:22 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_five_max(t_repo *repo)
{
	int		loop;
	int		i;
	t_stack	*stack;

	stack = repo->stack_a_first;
	loop = 1;
	i = 0;
	while (i < repo->size && loop)
	{
		if (stack->radix_value == 0 || stack->radix_value == 1)
			loop = 0;
		stack = stack->next;
		i++;
	}
	stack = repo->stack_a_first;
	if (i < 3)
	{
		while (stack->radix_value != 0 && stack->radix_value != 1)
		{
			ra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
		while (stack->radix_value != 0 && stack->radix_value != 1)
		{
			ra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
	}
	else
	{
		while (stack->radix_value != 0 && stack->radix_value != 1)
		{
			rra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
		while (stack->radix_value != 0 && stack->radix_value != 1)
		{
			ra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
	}
	stack_two_three(repo);
	stack = repo->stack_b_first;
	if (stack->radix_value < stack->next->radix_value)
		sb(repo);
	push_all_in_stack_a(repo);
	free_stack_a(repo);
	exit(EXIT_SUCCESS);
}
