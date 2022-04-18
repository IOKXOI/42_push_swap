/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:42 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/17 04:22:58 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	parsing(char **input);
int	fill_input(int *input, char **argv);
int	check_duplicate(int *input);

int main(int argc, char *argv[])
{
	int nb_arg;
	int *input;
	
	if (argc < 2)
		return(-1);
	nb_arg = parsing(argv);
	if (nb_arg == -1)
		return(-1);
	else 
		printf("nb_arg = %d\n", nb_arg);
	input = malloc(sizeof(int) * nb_arg);
	if (!input)
		return (-1);
	if (fill_input(input, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
//	while(nb_arg--)
//	{
//		printf("%d\n", *input);
	//	input++;
//	}
	if (check_duplicate(input) < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	
	return 0;
}
