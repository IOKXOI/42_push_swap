/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:19:29 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:12:35 by sydauria         ###   ########.fr       */
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

void	sa(t_repo *repo)
{
	t_stack	*stack_a;

	stack_a = repo->stack_a_first;
	repo->stack_a_first->next->prev = repo->stack_a_last;
	if (repo->stack_a_last->next)
		repo->stack_a_last->next = repo->stack_a_first->next;
	repo->stack_a_first = stack_a->next;
	repo->stack_a_first->prev = repo->stack_a_last;
	stack_a->next = repo->stack_a_first->next;
	stack_a->prev = repo->stack_a_first;
	stack_a->next->prev = stack_a;
	repo->stack_a_first->next = stack_a;
	repo->stack_a_last = repo->stack_a_first->prev;
	write(1, "sa\n", 3);
}

void	sb(t_repo *repo)
{
	t_stack	*stack_b;

	stack_b = repo->stack_b_first;
	repo->stack_b_first->next->prev = repo->stack_b_last;
	if (repo->stack_b_last->next)
		repo->stack_b_last->next = repo->stack_b_first->next;
	repo->stack_b_first = stack_b->next;
	stack_b->next = repo->stack_b_first->next;
	stack_b->prev = repo->stack_b_first;
	stack_b->next->prev = stack_b;
	repo->stack_b_first->next = stack_b;
	//if (repo->stack_b_last->next == repo->stack_b_last->next)
	repo->stack_b_last = repo->stack_b_first->prev;
	write(1, "sb\n", 3);
}

void	pa(t_repo *repo)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = repo->stack_a_first;
	stack_b = repo->stack_b_first;
	if (!stack_a)
	{
		init_first_node_in_stack_a(repo);
		write(1, "pa\n", 3);
		return ;
	}
	if (stack_b == stack_b->next)
		repo->stack_b_first = NULL;
	else if (repo->size > 4)
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = repo->stack_a_first;
	stack_b = repo->stack_b_first;
	if (!stack_b)
	{
		init_first_node_in_stack_b(repo);
		write(1, "pb\n", 3);
		return ;
	}
	if (stack_a == stack_a->next)
		repo->stack_a_first = NULL;
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

void	rra(t_repo *repo)
{
	repo->stack_a_first = repo->stack_a_last;
	repo->stack_a_last = repo->stack_a_last->prev;
	write(1, "rra\n", 4);
}

void	stack_two_three(t_repo *repo)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	a = repo->stack_a_first;
	b = a->next;
	if (repo->size == 2)
	{
		sa(repo);
		//free input?
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	c = b->next;
	if (a->radix_value < b->radix_value && b->radix_value > c->radix_value && c->radix_value > a->radix_value)
		acb(repo);
	else if (a->radix_value < b->radix_value && b->radix_value > c->radix_value && c->radix_value < a->radix_value)
		bca(repo);
	else if (a->radix_value > b->radix_value && b->radix_value < c->radix_value && c->radix_value > a->radix_value)
		bac(repo);
	else if (a->radix_value > b->radix_value && b->radix_value < c->radix_value && c->radix_value < a->radix_value)
		cab(repo);
	else if (a->radix_value > b->radix_value && b->radix_value > c->radix_value && c->radix_value < a->radix_value)
		cba(repo);
}
