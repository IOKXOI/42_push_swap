/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:42:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/12 15:09:04 by sydauria         ###   ########.fr       */
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
}

void	push_all_in_stack_a(t_repo *repo)
{
	t_stack	*stack_b;
	
	stack_b = repo->stack_b_first;
	while(stack_b != repo->stack_b_last)
		pa(repo->stack_a_first, stack_b, repo);
	pa(repo->stack_a_first, stack_b, repo);
}

void	radix(t_repo *repo)
{
	int	i;
	int	x;
	t_stack	*stack_a = repo->stack_a;

	i = 0;
	x = 0;
	stack_a = repo->stack_a_first;
	while (i < repo->size || x < 32)
	{
		if ((stack_a->radix_value >> x) == 0)
			ra(repo);
		else
			pb(stack_a, repo->stack_b, repo);
		if (i == repo->size)
		{
			push_all_in_stack_a(repo);
			i = 0;
			x++;
		}
		stack_a = repo->stack_a_first;
	}
}
