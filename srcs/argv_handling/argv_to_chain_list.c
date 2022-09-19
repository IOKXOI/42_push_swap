/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_chain_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:46:59 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:14:33 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_repo *repo, int *input)
{
	repo->stack_a_first = malloc(sizeof(t_stack));
	if (!repo->stack_a_first)
	{
		free(input);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	repo->stack_a_first->next = NULL;
	repo->stack_a_last = repo->stack_a_first;
}

static t_stack	*new_node(t_repo *repo, int *input)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_stack_a(repo);
		free(input);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node->prev = repo->stack_a_last;
	new_node->next = repo->stack_a_first;
	repo->stack_a_first->prev = new_node;
	repo->stack_a_last->next = new_node;
	repo->stack_a_last = new_node;
	return (new_node);
}

void	init_chain_list_and_fill_it(int *input, t_repo *repo)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	init_stack(repo, input);
	stack_a = repo->stack_a_first;
	stack_a->value = input[i];
	i++;
	while (i < repo->size)
	{
		stack_a->next = new_node(repo, input);
		stack_a = stack_a->next;
		stack_a->value = input[i];
		i++;
	}
	repo->stack_a_last = stack_a;
	repo->stack_a_last->next = repo->stack_a_first;
	repo->stack_b_first = NULL;
}
