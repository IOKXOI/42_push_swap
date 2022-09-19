/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:46 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:03:23 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				radix_value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct t_repo
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_a_first;
	t_stack	*stack_a_last;
	t_stack	*stack_b;
	t_stack	*stack_b_first;
	t_stack	*stack_b_last;
}	t_repo;

// INIT ///////////////////////////////////////////////////////////////////////
void	init_chain_list_and_fill_it(int *input, t_repo *repo);
int		parsing(char **input);
void	check_duplicate(int *input, t_repo *repo);
void	is_already_sorted(int *input, t_repo *repo);
///////////////////////////////////////////////////////////////////////////////

// CONVERT_TO_INT* ////////////////////////////////////////////////////////////
int*	fill_input(t_repo *repo, char **argv);
///////////////////////////////////////////////////////////////////////////////

// FREE ///////////////////////////////////////////////////////////////////////
void	free_stack_a(t_repo *repo);
///////////////////////////////////////////////////////////////////////////////

// LIST ///////////////////////////////////////////////////////////////////////
void	get_value_in_node(int node_value, int index, t_repo *repo);
void	init_first_node_in_stack_a(t_repo *repo);
void	init_first_node_in_stack_b(t_repo *repo);
int		is_already_sorted_list(t_repo *repo);
///////////////////////////////////////////////////////////////////////////////

// RADIX //////////////////////////////////////////////////////////////////////
void	radix(t_repo *repo);
void	sort_by_index(int *input, t_repo *repo);
void	push_all_in_stack_a(t_repo *repo);
///////////////////////////////////////////////////////////////////////////////

// MOOVES /////////////////////////////////////////////////////////////////////
void	sa(t_repo *repo);
void	sb(t_repo *repo);
void	pa(t_repo *repo);
void	pb(t_repo *repo);
void	ra(t_repo *repo);
void	rra(t_repo *repo);
void	acb(t_repo *repo);
void	bca(t_repo *repo);
void	bac(t_repo *repo);
void	cab(t_repo *repo);
void	cba(t_repo *repo);
void	stack_two_three(t_repo *repo);
void	stack_four(t_repo *repo);
void	stack_five_max(t_repo *repo);

//void	rb(t_repo *repo);
//void	rr(t_repo *repo);
//void	rra(t_repo *repo);
//void	rrb(t_repo *repo);
//void	rrr(t_repo *repo);
///////////////////////////////////////////////////////////////////////////////

void print_stacks(t_repo *repo);
# endif
