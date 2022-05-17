/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:53:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/11 12:10:43 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_lis(int *input, t_sub *sub, t_lis *repo)
{
	int	i;
	int	tmp_max;

	i = 0;
	repo = malloc(sizeof(t_lis));
	while (input[i])
	{
		if (input[] > tmp_max)
			add_to_list();
		if (input[] < tmp_max && input[] > first)
		{
			new_list = create_new_list();
			get_lis(new_list);
		}
		if (input[] < tmp_max && input[] > first)
		{
			new_list = create_new_list();
			get_lis(new_list);
		}

	}
}

t_storage *count_subsequences(t_stacks *input, t_storage *posibilities)
{
	t_sub  *lis;
	
	posibilities->sequence = init_first_sequence(lis);
	if (!posibilities->sequence)
		return (NULL);
	while (input)
	{
		if (lis->value < input->value)
		{
			lis->next = new_max_value(posibilities, input, lis);
			lis = lis->next;
		}
		else if (lis->value > input->value && 
					lis->min < input->value)
		{
			posibilities->next = new_max_sub_fork(posibilities, input, lis);
		}
		else if (lis->value > input->value && 
					lis->min > input->value)
		{
			posibilities->next = new_first_sub_fork(posibilities, input, lis);
		}
		input = input->next;
	}
	posibilities = posibilities->next;
	return (posibilities);
}

static t_sub	*new_max_value(t_storage *posibilities, t_stacks *input, t_sub *subsequence)
{
	t_sub	*new_max;

	new_max = malloc(sizeof(t_sub));
	if (!new_max)
		return (NULL);
	subsequence->next = new_max;
	new_max->min = subsequence->min;
	new_max->value = input->value;
	new_max->size = (subsequence->size) + 1;
	new_max->first_of_sub = subsequence->first_of_sub;
	new_max->root = subsequence;
	new_max->next = NULL;
	posibilities->lis_size += 1;
	return (new_max);
}

static t_sub	*new_sub_fork(t_storage *posibilities, t_stacks *input, t_sub *subsequence)
{
	t_storage	*fork_index;
	t_sub		*new_fork;

	fork_index = malloc(sizeof(t_storage));
	new_fork = malloc(sizeof(t_sub));
	if (!fork_index || !new_fork)
		return (NULL);
	posibilities->next = fork_index;
	fork_index->sequence = new_fork;
	fork_index->next = NULL;
	fork_index->lis_size = subsequence->size;
	new_fork->min = input->value;
	new_fork->value = input->value;
	new_fork->size = subsequence->size;
	new_fork->first_of_sub = new_fork;
	new_fork->root = subsequence;
	new_fork->next->next = NULL;
	posibilities->lis_size = new_fork->size;
	return (new_fork);
}

static t_sub	*new_first_sub_fork(t_storage *posibilities, t_stacks *input, t_sub *subsequence)
{
	t_storage	*fork_index;
	t_sub		*new_fork;

	fork_index = malloc(sizeof(t_storage));
	new_fork = malloc(sizeof(t_sub));
	if (!fork_index || !new_fork)
		return (NULL);
	posibilities->next = fork_index;
	fork_index->sequence = new_fork;
	fork_index->next = NULL;
	fork_index->lis_size = 1;
	new_fork->min = input->value;
	new_fork->value = input->value;
	new_fork->size = 1;
	new_fork->first_of_sub = new_fork; 
	new_fork->root = NULL;
	new_fork->next = NULL;
	posibilities->lis_size = new_fork->size;
	return (new_fork);
}

//dup_lis_and_free()



