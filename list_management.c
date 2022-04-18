/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:08:00 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/15 14:52:04 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*create_and_init_node(t_struct *first_node, t_struct last_node);
{
	t_struct	*new_node;

	new_node = (sizeof(t_struct));
	if (!new_node)
		return (NULL);
	last_node->next = new_node;
	new_node->value = 0;
	new_node->prev = last_node; 
	first_node->prev = new_node;
	return (new_node);
}

void sa(t_struct *first_node, t_struct *second_node)
{
	if(first_node->next)
	{
		second_node->previous = first_node->previous;
		first_node->previous->next = second_node;
		first_node->previous = second_node;
		first_node->next = second_node->next;
		second_node->next = first_node;
	}
}

void ra(t_struct *first_node, t_struct *last_node)
{
	if (!first_node || !last_node)
		return (NULL);
	last_node->next = first_node->next;
	first_node->next = last_node;
	first_node->previous = last_node->previous;
	last_node->previous = first_node;
}


