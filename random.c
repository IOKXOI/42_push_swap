/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:20:08 by nvasilev          #+#    #+#             */
/*   Updated: 2022/05/27 02:04:19 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

static void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("%d\n", arr[i]);
}

static int	check_if_exists(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

static void	fill_array(int *arr, int size)
{
	int				i;
	int				num;
	unsigned int	divider;
	int				tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

	divider = RAND_MAX / size;
	num = rand() % divider;
	divider = tens[((time(NULL)) + num) % 10];
	i = 0;
	while (i < size)
	{
		num = rand() % divider;
		divider = tens[((time(NULL)) + num) % 10];
		if (divider == 0)
			divider = 10;
		if ((time(NULL) + num) % 2)
			num *= -1;
		if (check_if_exists(arr, i, num))
			continue ;
		arr[i] = num;
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	numbers;
	int	*arr;

	if (argc == 2)
	{
		numbers = atoi(argv[1]);
		arr = (int *)malloc(sizeof(int) * numbers);
		if (arr == NULL)
			return (1);
		srand(time(NULL));
		if (numbers > 0)
		{
			fill_array(arr, numbers);
			print_array(arr, numbers);
		}
		free(arr);
	}
	else
		dprintf(STDERR_FILENO, "Usage: ./random <number>\n");
	return (0);
}
