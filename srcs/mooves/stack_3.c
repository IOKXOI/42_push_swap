/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 21:27:02 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/19 18:20:37 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	acb(t_repo *repo)
{
	rra(repo);
	sa(repo);
	if (repo->size <= 3)
	{
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	bca(t_repo *repo)
{
	rra(repo);
	if (repo->size <= 3)
	{
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	bac(t_repo *repo)
{
	sa(repo);
	if (repo->size <= 3)
	{
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	cab(t_repo *repo)
{
	ra(repo);
	if (repo->size <= 3)
	{
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	cba(t_repo *repo)
{
	ra(repo);
	sa(repo);
	if (repo->size <= 3)
	{
		free_stack_a(repo);
		exit(EXIT_SUCCESS);
	}
	return ;
}
