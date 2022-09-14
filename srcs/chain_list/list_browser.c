/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_browser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:51:05 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/13 15:38:58 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_value_in_node(int node_value, int index, t_repo *repo)
{
	t_stack *stack;

	stack = repo->stack_a_first;
	while (node_value != stack->value)
		stack = stack->next;
	stack->radix_value = index;
}

void	init_first_node_in_stack(t_repo *repo)
{
	repo->stack_b_first = repo->stack_a_first;
	repo->stack_b_last = repo->stack_a_first;
	repo->stack_a_first = repo->stack_a_first->next;
	repo->stack_a_first-> prev = repo->stack_a_last;
	repo->stack_a_last->next = repo->stack_a_first;
	repo->stack_b_first->next = NULL;
	repo->stack_b_first->prev = NULL;
}
