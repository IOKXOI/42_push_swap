/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 23:29:30 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
