/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:57:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/22 18:21:26 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_section	*get_lis(t_stack *stack_a, t_section *lis) // ici le min de stack_a
{
	t_stack		*limit;
	t_section	*lis;
	t_section	*new_section;
	t_section	*last_commun;
	t_section	*next_commun;
	
	duplicate_node(stack_a, lis);
	if (!lis)
		free_list(stack_a);
	limit = stack_a;
	stack_a = stack_a->next;
	while (stack_a != limit)
	{
		if (stack_a->value > lis->value)
		{
			if (!lis->next)
			{
				if (!duplicate_node(stack_a, lis->next))
				{
					free_list(stack_a);
					free_list(lis);
				}
			}
			stack_a = stack_a->next;
		}
		if (stack_a->value < lis->value)
		{
			new_section = get_last_commun(stack_a, lis);
			next_commun = get_next_commun(stack_a, lis);
			if (better_way(new_section, next_commun) > lis->score + 1)
			{
				free_list(new_section->next);
				new_section->next = duplicate_node(stack_a, new_section);
			}
		}
		stack_a = stack_a->next;
	}
	return (lis);
}


