/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/12 00:11:07 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///////////////DEBUG//////////////////////////////////
void print_stack(t_repo *repo)
{
	int	i = 1;
	while (i <= repo->size)
	{
		if (repo->stack_a == repo->stack_a_first)
		{
			printf("first node value = %d\n", repo->stack_a->value);
			printf(" radix value = %d\n", repo->stack_a->radix_value);
		}
		else if (repo->stack_a == repo->stack_a_last)
		{
			printf("last node value = %d\n", repo->stack_a->value);
			printf(" radix value = %d\n", repo->stack_a->radix_value);
		}
		else
		{
			printf("Node numero %d value = %d\n", i, repo->stack_a->value);
			printf(" radix value = %d\n", repo->stack_a->radix_value);
		}
		repo->stack_a = repo->stack_a->next;
		i++;
	}
}
////////////////////////////////////////////////////////

int	main(int argc, char *argv[])
{
	int			*input;
	t_repo		repo;

	if (argc < 2)
		return (0);
	repo.size = parsing(argv);
	if (repo.size < 2)
		return (0);
	input = fill_input(&repo, argv);
	check_duplicate(input, &repo);
	is_already_sorted(input, &repo);
	init_chain_list_and_fill_it(input, &repo);
	sort_by_index(input, &repo);
	radix(&repo);
	//repo.stack_a = repo.stack_a_first;
	//ra(&repo);
	//
	print_stack(&repo);
	//
	free(input);
	free_stack_a(&repo);
}

