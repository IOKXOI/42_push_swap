/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:10:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/13 14:46:02 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_a(t_repo *repo)
{
	int	i;
	t_stack	*save;
	t_stack	*stack_a;

	i = 0;
	stack_a = repo->stack_a_first;
	while (i < repo->size)
	{
		save = stack_a->next;
		free(stack_a);
		stack_a = save;
		i++;
	}
}
