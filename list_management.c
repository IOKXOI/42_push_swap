/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:08:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/28 12:36:14 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int init_stacks(int *input, t_save *stack_a, t_save *stack_b)
{
	int			i;
	t_stacks	*tmp_a;
	t_stacks	*tmp_b;

	i = 0;
	if (stack_a->first == NULL)
		stack_a->first = malloc(sizeof(t_stacks));
		if (!stack_a->first)
			return (-1);
	tmp_a = stack_a->first;
	if (stack_b->first == NULL)
		stack_b->first = malloc(sizeof(t_stacks));
		if (!stack_b->first)
				return (-1);
	tmp_b = stack_b->first;
	while (input[i])
	{
		tmp_a->value = input[i];
		if (input[i + 1])
		{
			tmp_a->next = malloc(sizeof(t_stacks));
			if (!tmp_a->next)
				return (-1);
			tmp_b->next = malloc(sizeof(t_stacks));
			if (!tmp_b->next)
				return (-1);
			tmp_a->next->prev = tmp_a;
			tmp_b->next->prev = tmp_b;
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		i++;
	}
	stack_a->last = tmp_a;
	stack_b->last = tmp_b;
	stack_a->last->next = stack_a->first;
	stack_a->first->prev = stack_a->last;
	stack_b->last->next = stack_b->first;
	stack_b->first->prev = stack_b->last;
}

int fill_stack(int *input, t_stacks *stack_a) //t_save stack_a->first;
{
	int	i;

	i = 0;
	if (check_duplicate(input) < 0)
		return (-1);
	while (input[i])
	{
		stack_a->value = input[i];
		stack_a = stack_a->next;
		i++;
	}
	free(input);
	return (0);
}
