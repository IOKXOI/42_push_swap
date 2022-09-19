/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:49:20 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 23:22:04 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_two_three(t_repo *repo)
{
	int	a;
	int	b;
	int	c;

	a = repo->stack_a_first->radix_value;
	b = repo->stack_a_first->next->radix_value;
	if (repo->size == 2)
	{
		sa(repo);
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	c = repo->stack_a_first->next->next->radix_value;
	if (a < b && b > c && c > a)
		acb(repo);
	else if (a < b && b > c && c < a)
		bca(repo);
	else if (a > b && b < c && c > a)
		bac(repo);
	else if (a > b && b < c && c < a)
		cab(repo);
	else if (a > b && b > c && c < a)
		cba(repo);
}

int	best_rotation(t_repo *repo)
{
	int		loop;
	int		i;
	t_stack	*stack;

	loop = 1;
	i = 0;
	stack = repo->stack_a_first;
	while (i < repo->size && loop)
	{
		if (stack->radix_value == 0 || stack->radix_value == 1)
			loop = 0;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ra_rotation(t_repo *repo)
{
	t_stack	*stack;

	stack = repo->stack_a_first;
	while (stack->radix_value != 0 && stack->radix_value != 1)
	{
		ra(repo);
		stack = repo->stack_a_first;
	}
	pb(repo);
}

void	rra_rotation(t_repo *repo)
{
	t_stack	*stack;

	stack = repo->stack_a_first;
	while (stack->radix_value != 0 && stack->radix_value != 1)
	{
		rra(repo);
		stack = repo->stack_a_first;
	}
	pb(repo);
}

void	stack_five_max(t_repo *repo)
{
	int		i;
	t_stack	*stack;

	stack = repo->stack_a_first;
	i = best_rotation(repo);
	stack = repo->stack_a_first;
	if (i < 3)
	{
		ra_rotation(repo);
		ra_rotation(repo);
	}
	else
	{
		rra_rotation(repo);
		rra_rotation(repo);
	}
	stack_two_three(repo);
	stack = repo->stack_b_first;
	if (stack->radix_value < stack->next->radix_value)
		sb(repo);
	push_all_in_stack_a(repo);
	free_stack_a(repo);
	exit(EXIT_SUCCESS);
}
