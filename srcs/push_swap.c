/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:22:33 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///////////////DEBUG//////////////////////////////////
/*
void	print_stack(t_repo *repo)
{
	int	i = 1;
	int	ok = 1;

	t_stack *stack_a = repo->stack_a_first;
	printf("========================\n");
	while (ok)
	{
		if (stack_a == repo->stack_a_first)
		{
			//printf("first node value = %d", stack_a->value);
			printf("%d\n\n", stack_a->radix_value);
			//printf("first = %p\nlast = %p\n actu = %p\n", )
		}
		else if (stack_a == repo->stack_a_last)
		{
			//printf("last node value = %d", stack_a->value);
			printf("%d\n\n", stack_a->radix_value);
		}
		else
		{
			//printf("Node numero %d value = %d", i, stack_a->value);
			printf("%d\n\n", stack_a->radix_value);
		}
		if (stack_a == repo->stack_a_last)
			ok = 0;
		stack_a = stack_a->next;
		i++;
	}
	printf("========================\n");
}
*/
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
	if (repo.size <= 3)
		stack_two_three(&repo);
	if (repo.size == 4)
		stack_four(&repo);
	if (repo.size == 5)
		stack_five_max(&repo);
	radix(&repo);
	free_stack_a(&repo);
}
