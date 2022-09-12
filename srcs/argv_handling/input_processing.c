/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:01:27 by sydauria          #+#    #+#             */
/*   Updated: 2022/09/10 00:49:57 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_int(long long nb, int sign, int *input)
{
	if (nb * sign < INT_MIN || nb * sign > INT_MAX)
	{
		free(input);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

static int	ft_multi_atoi(int *input, int count, char *argv, int sign)
{
	size_t	nb;
	int		k;

	k = 0;
	while (argv[k])
	{
		nb = 0;
		while (argv[k] == ' ' || (argv[k] >= 9 && argv[k] <= 13)
			|| argv[k] == '+' || argv[k] == '-')
		{
			if (argv[k] == '-')
				sign *= -1;
			k++;
		}
		if (argv[k] >= '0' && argv[k] <= '9')
		{
			while (argv[k] >= '0' && argv[k] <= '9')
			{
				nb = nb * 10 + (argv[k] - '0');
				k++;
				check_int((long long)nb, sign, input);
			}
			input[count] = sign * nb;
			sign = 1;
			count++;
		}
	}
	return (count);
}

int	*fill_input(t_repo *repo, char **argv)
{
	int	i;
	int	word_count;
	int	*input;

	input = malloc(sizeof(int) * (repo->size));
	if (!input)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	i = 1;
	word_count = 0;
	while (argv[i] && word_count < repo->size)
	{
		word_count = ft_multi_atoi(input, word_count, argv[i], 1);
		i++;
	}
	return (input);
}
