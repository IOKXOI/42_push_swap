/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:19:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/11 13:22:05 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stacks *first_node, t_stacks *second_node)
{
	int	temp;

	temp = first_node->value;
	first_node->value = second_node->value;
	second_node->value = temp;
	write(1, "sa\n", 3);
}

void sb(t_stacks *first_node, t_stacks *second_node)
{
	int	temp;

	temp = first_node->value;
	first_node->value = second_node->value;
	second_node->value = temp;
	write(1, "sb\n", 3);
}

void ss(t_stacks *stack_a, t_stacks *stack_b)
{
	sa(stack_a, stack_a->next);
	sb(stack_b, stack_b->next);
	write(1, "ss\n", 3);
}

void ra(t_save *stack_a)
{
	stack_a->last = stack_a->first;
	stack_a->first = stack_a->first->next;
	write(1, "ra\n", 3);
}

void rb(t_save *stack_b)
{
	stack_b->last = stack_b->first;
	stack_b->first = stack_b->first->next;
	write(1, "rb\n", 3);
}

void rr(t_save *stack_a, t_save *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void rra(t_save *stack_a)
{
	stack_a->first = stack_a->last;
	stack_a->last = stack_a->last->prev;
	write(1, "rra\n", 4);
}

void rrb(t_save *stack_b)
{
	stack_b->first = stack_b->last;
	stack_b->last = stack_b->last->prev;
	write(1, "rrb\n", 4);
}

void rrr(t_save *stack_a, t_save *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}

void pa(t_stacks *stack_a, t_stacks *stack_b)
{
	stack_a->prev->next = stack_a->next;
	stack_a->next->prev = stack_a->prev;
	stack_b->prev->next = stack_a;
	stack_b->next->prev = stack_a;
	stack_a->next = stack_b;
	stack_a->prev = stack_b->prev;
	write(1, "pa\n", 3);
}

void pb(t_stacks *stack_b, t_stacks *stack_a)
{
	stack_b->prev->next = stack_b->next;
	stack_b->next->prev = stack_b->prev;
	stack_a->prev->next = stack_b;
	stack_a->next->prev = stack_b;
	stack_b->next = stack_a;
	stack_b->prev = stack_a->prev;
	write(1, "pb\n", 3);
}
