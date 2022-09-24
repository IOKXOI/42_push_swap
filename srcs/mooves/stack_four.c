/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:00:44 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/24 18:46:12 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_four(t_repo *repo)
{
	int		i;

	i = best_rotation(repo);
	if (i < 3)
		ra_rotation(repo);
	else
		rra_rotation(repo);
	stack_two_three(repo);
	push_all_in_stack_a(repo);
	free_stack_a(repo);
	exit(EXIT_SUCCESS);
}
