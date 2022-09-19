/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:42:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 23:30:00 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_by_radix_value(int *input, int last_saved, int index, t_repo *repo)
{
	int	i;
	int	actual_min;

	i = 0;
	get_value_in_node(last_saved, 0, repo);
	index = 1 ;
	while (index < repo->size)
	{
		actual_min = INT_MAX;
		while (i < repo->size)
		{
			if (input[i] <= actual_min)
			{
				if (input[i] > last_saved)
					actual_min = input[i];
			}
			i++;
		}
		get_value_in_node(actual_min, index, repo);
		last_saved = actual_min;
		index++;
		i = 0;
	}
	return (actual_min);
}

void	sort_by_index(int *input, t_repo *repo)
{
	int	i;
	int	index;
	int	last_saved;

	i = 0;
	last_saved = input[i];
	i++;
	index = 0 ;
	while (i < repo->size)
	{
		if (input[i] < last_saved)
			last_saved = input[i];
		i++;
	}
	sorting_by_radix_value(input, last_saved, index, repo);
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
