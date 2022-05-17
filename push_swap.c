/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/05/13 23:53:04 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	parsing(char **input);
int	fill_input(int *input, char **argv);
int	check_duplicate(int *input, int size);
int	init_stacks(int *input, t_save *stack_a, t_save *stack_b);
int	free_stacks(t_save *stack_a, t_save *stack_b);

int main(int argc, char *argv[])
{
	int		*input;
	t_save	*stack_a;
	t_save	*stack_b;

	stack_a = malloc(sizeof(t_save));
	stack_b = malloc(sizeof(t_save));
	if (!stack_a || !stack_b)
		return (0);
	if (argc < 2)
		return(0);
	stack_a->size = parsing(argv);
	printf("stack->size %d ", stack_a->size);
	if (stack_a->size < 2)
		return(0);
	input = malloc(sizeof(int) * stack_a->size);
	if (!input)
		return (0);
	if (fill_input(input, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_duplicate(input, stack_a->size) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
		if (init_stacks(input, stack_a, stack_b) == 0)
			return (0);
	while (stack_a->first)
	{
		if (stack_a->first == stack_a->last)
		{
			write(1, "Stack ok\n", 9);
			return (free_stacks(stack_a, stack_b));
		}
		stack_a->first = stack_a->first->next;
	}
	return 1;
}

