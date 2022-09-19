/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:10:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:15:29 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_a(t_repo *repo)
{
	int		i;
	int		loop;
	t_stack	*save;
	t_stack	*stack_a;

	i = 0;
	loop = 1;
	stack_a = repo->stack_a_first;
	save = repo->stack_a_first;
	while (loop && (i < repo->size))
	{
		if (save == repo->stack_a_last)
			loop = 0;
		save = stack_a->next;
		if (stack_a)
			free(stack_a);
		stack_a = save;
		i++;
	}
}
