/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_browser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:51:05 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/11 23:05:44 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_value_in_node(int node_value, int index, t_repo *repo)
{
	t_stack *stack;

	stack = repo->stack_a_first;
	while (node_value != stack->value)
		stack = stack->next;
	stack->radix_value = index;
}
