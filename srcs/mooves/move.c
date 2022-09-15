/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:19:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/15 02:07:13 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect_node(t_stack *a, t_stack *b, t_stack *c, t_stack *d)
{
	if (a)
		a->next = b;
	b->prev = a;
	b->next = c;
	c->prev = b;
	c->next = d;
	if (d)
		d->prev = c;
}

/*void	push(t_stack *stack_out, t_stack *stack_in)
{
	if (stack_in->prev)
	{
		stack_in->prev->next = stack_out;
		stack_out->prev = stack_in->prev;
	}
	stack_in->pre
}
*/
void	sa(t_repo *repo)
{
	t_stack *stack_a;
	
	stack_a = repo->stack_a_first;
	repo->stack_a_first = stack_a->next;
	repo->stack_a_last->next = repo->stack_a_first;
	repo->stack_a_first->prev = repo->stack_a_last;
	stack_a->next = repo->stack_a_first->next;
	stack_a->next->prev = stack_a;
	repo->stack_a_first->next = stack_a;
	write(1, "sa\n", 3);
}
 /*
void	sb(t_repo *repo)
{
	t_stack	*stack_b;

	repo->stack_b_first = stack_b->next;
	stack_b->next->next->prev = stack_b;
	stack_b->prev->next = stack_b->next;
	stack_b->next->prev = stack_b->prev;
	stack_b->prev = stack_b->next;
	tmp = stack_b->next->next;
	stack_b->next->next = stack_b;
	stack_b->next = tmp;
	stack_b = repo->stack_b_first;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_repo *repo)
{
	t_stack	*tmp;

	repo->stack_a_first = stack_a->next;
	repo->stack_b_first = stack_b->next;
	stack_a->next->next->prev = stack_a;
	stack_a->prev->next = stack_a->next;
	stack_a->next->prev = stack_a->prev;
	stack_a->prev = stack_a->next;
	tmp = stack_a->next->next;
	stack_a->next->next = stack_a;
	stack_a->next = tmp;
	stack_b->next->next->prev = stack_b;
	stack_b->prev->next = stack_b->next;
	stack_b->next->prev = stack_b->prev;
	stack_b->prev = stack_b->next;
	tmp = stack_b->next->next;
	stack_b->next->next = stack_b;
	stack_b->next = tmp;
	stack_a = repo->stack_a_first;
	stack_b = repo->stack_b_first;
	write(1, "ss\n", 3);
}
*/
void	pa(t_repo *repo)
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_a = repo->stack_a_first;
	stack_b = repo->stack_b_first;
	if (!stack_a)
	{
		init_first_node_in_stack_a(repo);
		write(1, "pa\n", 3);
		return;
	}
	if (stack_b == stack_b->next)
	{
		repo->stack_b_first = NULL;
		repo->stack_b_last = NULL;
	}
	else
	{
		repo->stack_b_first = stack_b->next;
		repo->stack_b_first->prev = repo->stack_b_last;
		repo->stack_b_last->next = repo->stack_b_first;
	}
	stack_b->next = repo->stack_a_first;
	stack_b->next->prev = stack_b;
	repo->stack_a_first = stack_b;
	repo->stack_a_first->prev = repo->stack_a_last;
	repo->stack_a_last->next = repo->stack_a_first;
	write(1, "pa\n", 3);
}

void	pb(t_repo *repo)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = repo->stack_a_first;
	stack_b = repo->stack_b_first;
	if (!stack_b)
	{
		init_first_node_in_stack_b(repo);
		write(1, "pb\n", 3);
		return;
	}
	if (stack_a == stack_a->next)
	{
		repo->stack_a_first = NULL;
		repo->stack_a_last = NULL;
	}
	else
	{
		repo->stack_a_first = stack_a->next;
		repo->stack_a_first->prev = repo->stack_a_last;
		repo->stack_a_last->next = repo->stack_a_first;
	}
	stack_a->next = repo->stack_b_first;
	stack_a->next->prev = stack_a;
	repo->stack_b_first = stack_a;
	repo->stack_b_first->prev = repo->stack_b_last;
	repo->stack_b_last->next = repo->stack_b_first;
	write(1, "pb\n", 3);
}

void	ra(t_repo *repo)
{
	repo->stack_a_last = repo->stack_a_first;
	repo->stack_a_first = repo->stack_a_first->next;
	write(1, "ra\n", 3);
}
/*
void	rb(t_repo *repo)
{
	repo->stack_b_last = repo->stack_b_first;
	repo->stack_b_first = repo->stack_b_first->next;
	repo->stack_b = repo->stack_b_first; 
	write(1, "rb\n", 3);
}

void	rr(t_repo *repo)
{
	repo->stack_a_last = repo->stack_a_first;
	repo->stack_a_first = repo->stack_a_first->next;
	repo->stack_b_last = repo->stack_b_first;
	repo->stack_b_first = repo->stack_b_first->next;
	repo->stack_a = repo->stack_a_first; 
	repo->stack_b = repo->stack_b_first; 
	write(1, "rr\n", 3);
}

void	rra(t_repo *repo)
{
	repo->stack_a_first = repo->stack_a_last;
	repo->stack_a_last = repo->stack_a_last->prev;
	repo->stack_a = repo->stack_a_first; 
	write(1, "rra\n", 4);
}

void	rrb(t_repo *repo)
{
	repo->stack_b_first = repo->stack_b_last;
	repo->stack_b_last = repo->stack_b_last->prev;
	repo->stack_b = repo->stack_b_first; 
	write(1, "rrb\n", 4);
}

void	rrr(t_repo *repo)
{
	repo->stack_a_first = repo->stack_a_last;
	repo->stack_a_last = repo->stack_a_last->prev;
	repo->stack_b_first = repo->stack_b_last;
	repo->stack_b_last = repo->stack_b_last->prev;
	repo->stack_a = repo->stack_a_first; 
	repo->stack_b = repo->stack_b_first; 
	write(1, "rrr\n", 4);
}
*/
