/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:10:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/10 05:11:44 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack_a(t_repo *repo)
{
	t_stack	*save;
	int	i;

	i = 0;

	while (i < repo->size)
	{
		save = repo->stack_a->next;
		free(repo->stack_a);
		repo->stack_a = save;
		i++;
	}
}
