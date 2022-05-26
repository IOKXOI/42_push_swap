/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 07:53:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/26 18:57:58 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_section get_lis()
{
	insert_in_lis; // dup t_stack en t_section si lis
	{
		if (max < next)
		{	
			best_section() //trouve la
			{
				insert_in_lis()
				next_commun(void *, t_section *);
				{
					if (max < next)
						best_section();
				}
				best_way();
			}
		}
	}
}

t_section	*insert_in_lis(t_stack *stack_a, t_section *lis)
{
	int	i;
	int	actual_max;

	i = 0;
	actual_max = stack_a->value;
	while (i < stack_a->size)
	{
		actual_max = stack_a->value;
		copy_node(stack_a, lis->last);
		stack_a = stack_a->next;
		if (actual_max > stack_a->value)
		{
			insert_in_lis(last_commun(stack_a), lis);
		}
	}
}

t_section	*best_section(t_stack *stack_a, t_section *actual_lis)
{
	next_commun(stack_a, actual_lis);
	
}

t_section *next_commun(t_stack *stack_a, t_section *actual_lis)
{
	t_section	*new_section;
	t_section	*last_commun;
	int			actual_max;
	
	actual_max = stack_a->value;
	
	last_commun = actual_lis;
	while (last_commun-> )
	while (stack_a->value <= actual_max)
	{
		insert_in_list(stack_a->next, last_commun);
	}
	
	
}

t_section	*get_lis(t_stack *stack_a)
{
	int			i;
	int			actual_max;
	t_section	*lis;
	t_section	*last_commun;

	i = stack_a->score;
	while (i < stack_a->size)
	{
		actual_max = stack_a->value;
		copy_node(stack_a, lis->last);
		stack_a = stack_a->next;
		if (actual_max > stack_a->value)
		{
			last_commun = get_last_commun(stack_a, stack_a->value);
			create_new_section(stack_a, last_commun);
			new_section->next = duplicate_node(stack_a);
			
		}
	}
}

create_new_section(t_stack *stack_a, t_section *last_commun, t_section *next_commun, t_section *main_section)
{
	int			i;
	t_section	*new_section;
	t_section	*;

	i = last_commun->score;
	new_section = duplicate_node(last_commun);
	potential_free = new_section;
	while (new_section != next_commun)
	{
		stack_a = stack_a->next;
		new_section->next = duplicate_node(stack_a);
		new_section = new_section->next;
	}
	if (new_section->score <= next_commun->score)
	{
		free_list(potential_free);
	}
	if (new_section->score > next_commun->score)
	{
		last_commun->prev->next = 
		free_list(last_commun);
	}
	free ();
}

t_stack	*get_last_commun(t_stack *stack_a, int new_start)
{
	while (stack_a->value > new_start)
		stack_a = stack_a->prev;
	return (duplicate_node(stack_a));
}

t_section	*get_lis(t_stack *stack_a, t_section *lis)
{
	t_stack		*limit;
	t_section	*actual_section;
	t_section	*last_commun;
	t_section	*next_commun;

	actual_section = duplicate_node(stack_a); //free stack_a dans la fonction si erreur et exit;
	stack_a = stack_a->next;
	while (stack_a != limit)
	{
		if (actual_section->value > stack_a->value)
		{
			stack_a = best_way(actual_section, last_commun, next_commun);
		}
		else
		{
			actual_section->next = duplicate_node(stack_a);
			stack_a = stack_a->next;
		}
	}
	return(actual_section->first);
}

t_stack	*best_way(t_section *actual_section, t_section *last_commun, t_section *next_commun);
{
	t_section	*potential;
	
	potential = get_lis(stack_a);
	if (potential->size > )
}
