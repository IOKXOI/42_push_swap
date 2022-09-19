/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:16:03 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 21:16:36 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_repo *repo)
{
	repo->stack_a_last = repo->stack_a_first;
	repo->stack_a_first = repo->stack_a_first->next;
	write(1, "ra\n", 3);
}

void	rra(t_repo *repo)
{
	repo->stack_a_first = repo->stack_a_last;
	repo->stack_a_last = repo->stack_a_last->prev;
	write(1, "rra\n", 4);
}
