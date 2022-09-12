/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_chain_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:46:59 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/12 15:10:42 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_repo *repo)
{
	repo->stack_a = malloc(sizeof(t_stack));
	if (!repo->stack_a)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	repo->stack_a_first = repo->stack_a;
	repo->stack_a->next = NULL;
}

static t_stack	*new_node(t_repo *repo)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		free_stack_a(repo);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_node->prev = repo->stack_a;
	new_node->next = repo->stack_a_first;
	repo->stack_a_last = new_node;
	return (new_node);
}

void	init_chain_list_and_fill_it(int *input, t_repo *repo)
{
	int	i;

	i = 0;
	init_stack(repo);
	repo->stack_a->value = input[i];
	i++;
	while (i < repo->size)
	{
		repo->stack_a->next = new_node(repo);
		repo->stack_a = repo->stack_a->next;
		repo->stack_a->value = input[i];
		i++;
	}
	repo->stack_a = repo->stack_a_first; 
	repo->stack_a_first->prev = repo->stack_a_last;
	repo->stack_a_last->next = repo->stack_a_first;
	repo->stack_b = NULL;
}
