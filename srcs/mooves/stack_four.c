/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:00:44 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 23:20:51 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_four(t_repo *repo)
{
	int		i;
	t_stack	*stack;

	stack = repo->stack_a_first;
	i = best_rotation(repo);
	stack = repo->stack_a_first;
	if (i < 3)
		ra_rotation(repo);
	else
		rra_rotation(repo);
	stack_two_three(repo);
	stack = repo->stack_b_first;
	if (stack->radix_value < stack->next->radix_value)
		sb(repo);
	push_all_in_stack_a(repo);
	free_stack_a(repo);
	exit(EXIT_SUCCESS);
}