/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:01:34 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/17 04:36:20 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

int	check_duplicate(int *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i + 1])
	{
		j = i + 1;
		while (input[j])
		{
			if (input[i] == input[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_check_and_count(char *input)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (input[i])
	{
		while (input[i] == ' ' || (input[i] >= 9 && input[i] <= 13))
			i++;
		if (input[i] == '-' || input[i] == '+')
			i++;
		if (input[i] >= '0' && input[i] <= '9')
		{
			count++;
			while(input[i] >= '0' && input[i] <= '9')
				i++;
		}
		if (input[i])
			if(!(input[i] == ' ' || (input[i] >= 9 && input[i] <= 13)))
				return(-1);
	}
	return (count);
}

int	parsing(char **input)
{
	int	count;
	int	k;
	int	retrn;

	k = 1;
	count = 0;
	if (!**input)
		return (-1);
	while (input[k])
	{
		retrn = arg_check_and_count(input[k]);
		if (retrn < 0)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		k++;
		count += retrn;
	}
	return (count);
}
