/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:08:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/11 12:24:40 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static int	create_nodes(t_save *stack_a, t_save *stack_b, int input)
{
	stack_a->first = malloc(sizeof(t_stacks));
	stack_b->first = malloc(sizeof(t_stacks));
	if (!stack_a->first || !stack_a->first)
		return (0);
	stack_a->last = stack_a->first;
	stack_a->first->value = input;
	stack_b->last = stack_b->first;
	return (1);
}

static int	new_nodes(t_save *stack_a, t_save *stack_b, int input)
{
	stack_a->last->next = malloc(sizeof(t_stacks));
	stack_b->last->next = malloc(sizeof(t_stacks));
	if (!stack_a->first || !stack_a->first)
		return (0);
	stack_a->last->next->prev = stack_a->last;
	stack_a->last = stack_a->last->next;
	stack_a->last->value = input;
	stack_a->last->next = stack_a->first;
	stack_b->last->next->prev = stack_b->last;
	stack_b->last = stack_b->last->next;
	stack_b->last->next = stack_b->first;
	return (1);
}

int init_stacks(int *input, t_save *stack_a, t_save *stack_b)
{
	int			i;
	
	i = 0;
	if (create_nodes(stack_a, stack_b, input[i]) == 0)
		return (0);
	i++;
	while (i < stack_a->size)
	{
		if (new_nodes(stack_a, stack_b, input[i]) == 0)
			return (0);
		i++;
	}
	free(input);
	return (1);
}

void	free_node(t_save *stack)
{
	t_stacks *tmp;
	
	tmp = stack->first;
	stack->first = stack->first->next;
	free(tmp);
}

int	free_stacks(t_save *stack_a, t_save *stack_b)
{
	int i;
	i = 0;
	while (i < stack_a->size)
	{
		free_node(stack_a);
		free_node(stack_b);
		i++;
	}
	free(stack_a);
	free(stack_b);
	return (1);
}
