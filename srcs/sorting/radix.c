/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:42:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/15 00:12:51 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_index(int *input, t_repo *repo)
{
	int	i;
	int	index;
	int	actual_min;
	int last_number_saved;
	
	i = 0;
	last_number_saved = input[i];
	i++;
	while (i < repo->size)
	{
		if (input[i] < last_number_saved)
			last_number_saved = input[i];
		i++;
	}
	i = 0;
	index = 0 ;
	get_value_in_node(last_number_saved, index, repo);
	index++;
	while (index < repo->size)
	{
		actual_min = INT_MAX;
		while (i < repo->size)
		{
			if (input[i] <= actual_min)
			{
				if (input[i] > last_number_saved)
					actual_min = input[i];
			}
			i++;
		}
		get_value_in_node(actual_min, index, repo);
		last_number_saved = actual_min;
		index++;
		i = 0;
	}
	free(input);
}

void	push_all_in_stack_a(t_repo *repo)
{
	t_stack	*stack_b;
	
	stack_b = repo->stack_b_first;
	while(stack_b)
	{
		//print_stack(repo);
		pa(repo);
		stack_b = repo->stack_b_first;
	}
}

void	print_stacks(t_repo *repo)
{
	t_stack *stack_a = repo->stack_a_first;
	t_stack *stack_b = repo->stack_b_first;
	
	int a = 20;
	int b = 1;
	
	while (a)
	{
		if (stack_a && a)
		{
			if (stack_a == repo->stack_a_last)
				a--;
			printf("Value = %d radix_value = %d |", stack_a->value, stack_a->radix_value);
			stack_a = stack_a->next;
		}
		else
			printf("                            |");
		if (stack_b && b)
		{
			if (stack_b == repo->stack_b_last)
				b--;
			printf("Value = %d radix_value = %d |\n", stack_b->value, stack_b->radix_value);
			stack_b = stack_b->next;
		}
		else
			printf("                            |\n");
		a--;
	}
	exit(1);
	printf("==================");
}

void	radix(t_repo *repo)
{
	int	i;
	int	x;
	t_stack	*stack_a = repo->stack_a;

	i = 0;
	x = 0;
	stack_a = repo->stack_a_first;
	while (!is_already_sorted_list(repo) || repo->stack_b_first)
	{
		//print_stacks(repo);
		if ((stack_a->radix_value >> x & 1) == 1)
			ra(repo);
		else
			pb(repo);
		if (i == repo->size)
		{
			push_all_in_stack_a(repo);
			i = 0;
			printf("PUSH in a\n");
			x++;
		}
		i++;
		stack_a = repo->stack_a_first;
	}
}
