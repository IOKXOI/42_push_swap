/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:19:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/28 12:20:11 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stacks *first_node, t_stacks *second_node)
{
	int	temp;
	if(first_node->next)
	{
		temp = first_node->value;
		first_node->value = second_node->value;
		second_node->value = temp;
	}
}

void sb(t_stacks *first_node, t_stacks *second_node)
{
	int	temp;
	if(first_node->next)
	{
		temp = first_node->value;
		first_node->value = second_node->value;
		second_node->value = temp;
	}
}

void ss(t_stacks *stack_a, t_stacks *stack_b)
{
	sa(stack_a, stack_a->next);
	sb(stack_b, stack_b->next);
}

void ra(t_stacks *first_node, t_stacks *last_node)
{
	if (!first_node || !last_node)
		return (NULL);
	first_node->value = last_node
}

void rb(t_stacks **first_node, t_stacks **last_node)
{
	if (!first_node || !last_node)
		return (NULL);
	return (first_node->prev);
}

void rra(t_stacks **first_node, t_stacks **last_node)
{
	if (!first_node || !last_node)
		return (NULL);
	return (first_node->next);
}

void pa(t_stacks *stack_a, t_stacks *stack_b)
{
	if (!stack_a || !stack_b)
		return(NULL);
	stack_a->prev->next = stack_a->next;
	stack_a->next->prev = stack_a->prev;
	stack_b->prev->next = stack_a;
	stack_b->next->prev = stack_a;
	stack_a->next = stack_b;
	stack_a->prev = stack_b->prev;
}

void pb(t_stacks *stack_b, t_stacks *stack_a)
{
	if (!stack_b || !stack_a)
		return(NULL);
	stack_b->prev->next = stack_b->next;
	stack_b->next->prev = stack_b->prev;
	stack_a->prev->next = stack_b;
	stack_a->next->prev = stack_b;
	stack_b->next = stack_a;
	stack_b->prev = stack_a->prev;
}
