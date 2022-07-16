/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:53:46 by sydauria          #+#    #+#             */
/*   Updated: 2022/06/06 14:15:23 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
typedef struct s_longest_increasing_subsequence
{

	int			min;
	int			value;
	int			size;
	t_sub		*first_of_sub;
	t_sub		*root;
	t_sub		*next;
} t_sub;

typedef struct s_stacks
{
	t_stacks	*prev;
	int			value;
	int			it_is_lis;
	t_stacks	next;
} t_stacks;

typedef struct s_storage
{
	t_sub		*sequence;
	int 		lis_size;
	t_storage 	*next;
}t_storage;
*/
typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				score;
	int				size;
	int				alternative;
	struct s_stack	*next;
} t_stack;

typedef struct s_lis
{
	struct s_lis	*begin;
	struct s_lis	*prev;
	int				score;
	int				value;
	struct s_lis	*next;
} t_lis;

typedef struct s_save
{
	t_stack		*first;
	int			size;
	t_stack		*last;
	t_lis		*lis;
} t_save;



# endif
