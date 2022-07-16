/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:53:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/06/06 19:23:03 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_lis(t_lis *list);

static t_lis	*duplicate_node(t_stack *stack, t_lis *last)
{
	t_lis	*new_node;
	
	new_node = malloc(sizeof(t_lis));
	if (!new_node)
	{
		free_lis(last->begin);
		return(NULL);
	}
	new_node->begin = last->begin;
	new_node->prev = last;
	new_node->score = last->score + 1;
	new_node->value = stack->value;
	last->next = new_node;
	new_node->next = NULL;
	return (new_node);
}

static t_stack *last_commun(t_stack *stack, t_lis *lis)
{
	while (stack->value < lis->value && lis != lis->begin)
		lis = lis->prev;
	if (lis == lis->begin && lis->value > stack->value)
	{
		stack->score = 0;
		return (stack); // possible loop?
	}
	while (stack->value != lis->value)
		stack = stack->prev;
	stack->score = lis->score;
	return (stack);
}

static t_stack *next_commun(t_stack *stack, t_lis *lis)
{
	int	actual_max;
	int	score;
	
	actual_max = stack->prev->value;
	if (stack->score == 0)
	{
			actual_max = stack->value;
			stack->score = 1;
			stack = stack->next;
	}
	while (stack->value != lis->begin)
	{
		stack = stack->next;
		if (stack->value == lis->begin->value)
			return (stack->prev);
	}
	return (stack);
}

int	test_way(t_stack *last_commun, t_stack *next_commun, int alternative_value)
{
	int	actual_max;
	int	next_commun_value;
	int	alternative_condition;
	
	alternative_condition = 1;
	actual_max = last_commun->value;
	while (last_commun != next_commun)
	{
		last_commun = last_commun->next;
		if (last_commun->value > actual_max && 
			last_commun->value <= alternative_value)
		{
			actual_max = last_commun->value;
			last_commun->score ++;
			if (alternative_condition)
				last_commun->alternative = 1;
			if (last_commun->value == alternative_value)
			{
				alternative_value = next_commun->value;
				alternative_condition = 0;
			}
		}
	}
	return (last_commun->score);
}

t_lis	*last_commun_on_lis(t_stack *last_commun, t_lis *lis)
{
	while (lis->value != last_commun->value)
		lis = lis->prev;
	free_lis(lis->next);
	return (lis);
}

t_lis	*init_lis(t_stack *stack)
{
	t_lis	*first_node;

	first_node = malloc(sizeof(t_lis));
	if (!first_node)
		return (NULL);
	first_node->begin = first_node;
	first_node->prev = NULL;
	first_node->score = 1;
	first_node->value = stack->value;
	first_node->next = NULL;
}

static t_lis	*best_way(t_stack *stack, t_lis *lis_last)
{
	int		alter_score;
	t_stack	*last_commun_address;
	t_stack	*next_commun_address;
	
	last_commun_address = last_commun(stack, lis_last);
	next_commun_address = next_commun(stack, lis_last);
	alter_score = test_way(last_commun_address, next_commun_address, stack->value);
	if (alter_score >= lis_last->score)
	{
		if (last_commun_address->score == 0)
		{
			free_lis(lis_last->begin);
			lis_last = init_lis(stack);
		}
		while (last_commun_address->value != stack->value)
		{
			if (last_commun_address->alternative = 1)
			{
				last_commun_address->alternative = 0;
				lis_last = duplicate_node(stack, lis_last);
				if (!lis_last)
					return (NULL);
			}
			last_commun_address = last_commun_address->next;
		}
	}
	return (lis_last);
}

t_lis *get_lis(t_stack *stack)
{
	int		i;
	t_lis	*lis;

	i = 0;
	lis = init_lis(stack);
	if (!lis)
		return (NULL);
	stack = stack->next;
	while (stack->value != lis->begin->value)
	{
		if (stack->value > lis->value)
		{
			lis->next = duplicate_node(stack, lis);
			if (!lis->next)
				return (NULL);
			lis = lis->next;
		}
		else
		{
			lis = best_way(stack, lis);
			if (!lis)
				return (NULL);
		}
		stack = stack->next;
	}
	return (lis->begin);
}
