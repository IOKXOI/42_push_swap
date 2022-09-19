/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:00:44 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:26:18 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_four(t_repo *repo)
{
	int		loop;
	int		i;
	t_stack	*stack;

	stack = repo->stack_a_first;
	loop = 1;
	i = 0;
	while (i < repo->size && loop)
	{
		if (stack->radix_value == 0)
			loop = 0;
		stack = stack->next;
		i++;
	}
	stack = repo->stack_a_first;
	if (i < 3)
	{
		while (stack->radix_value != 0)
		{
			ra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
	}
	else
	{
		while (stack->radix_value != 0)
		{
			rra(repo);
			stack = repo->stack_a_first;
		}
		pb(repo);
		stack = repo->stack_a_first;
	}
	stack_two_three(repo);
	stack = repo->stack_b_first;
	pa(repo);
	free_stack_a(repo);
	exit(EXIT_SUCCESS);
}
