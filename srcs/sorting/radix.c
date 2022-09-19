/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:42:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:37:30 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	

void	sort_by_index(int *input, t_repo *repo)
{
	int	i;
	int	index;
	int	actual_min;
	int	last_number_saved;

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
	i = 0;
	while (i < repo->size)
		i++;
	free(input);
}

void	push_all_in_stack_a(t_repo *repo)
{
	t_stack	*stack_b;

	stack_b = repo->stack_b_first;
	while (stack_b != repo->stack_b_last)
	{
		pa(repo);
		stack_b = repo->stack_b_first;
	}
	pa(repo);
}
/*
void	print_stacks(t_repo *repo)
{
	t_stack	*stack_a = repo->stack_a_first;
	t_stack	*stack_b = repo->stack_b_first;
	
	int a = 1;
	int b = 1;
	
	if (stack_a)
	{
		printf("STACK_A\n");
		while (a)
		{
			if (stack_a == repo->stack_a_last)
				a = 0;
			printf("radix_value = %d |\n", stack_a->radix_value);
			stack_a = stack_a->next;
		}
	}
	printf("_________________\n");
	if (stack_b)
	{
		printf("STACK_b\n");
		while (b)
		{
			if (stack_b == repo->stack_b_last)
				b = 0;
			printf("radix_value = %d |\n", stack_b->radix_value);
			stack_b = stack_b->next;
		}
	}
	printf("                 \n");
//	printf("==================\n");
}
*/

void	radix(t_repo *repo)
{
	int		i;
	int		x;
	t_stack	*stack_a;

	i = 0;
	x = 0;
	stack_a = repo->stack_a;
	stack_a = repo->stack_a_first;
	while ((!is_already_sorted_list(repo) || repo->stack_b_first) && i < 1000)
	{
		if ((stack_a->radix_value >> x & 1) == 1)
			ra(repo);
		else
			pb(repo);
		if (i == repo->size)
		{
			push_all_in_stack_a(repo);
			i = 0;
			x++;
		}
		i++;
		stack_a = repo->stack_a_first;
	}
}
