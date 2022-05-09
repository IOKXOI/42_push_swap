/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:09:59 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/27 22:47:39 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	count_min(t_stacks *min, t_save *save)
{
	int	count;

	while(min != save->first)
	{
		min = min->prev;
		count++;
	}
	return (count);
}

int	count_max(t_stacks *max, t_save *save)
{
	int	count;

	while(max != save)
	{
		max = max->prev;
		count++;
	}
	count++;
	return(count);
}
