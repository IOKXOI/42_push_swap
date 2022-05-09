/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:58 by sydauria          #+#    #+#             */
/*   Updated: 2022/04/27 22:56:21 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_argv_count(const char *str)
{
	size_t argv_count;

	argv_count = 0;

	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '+' || *str == '-')
				str++;
		if (*str >= '0' && *str <= '9')
		{
			argv_count++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
	}
	return (argv_count);
}

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

int main(int argc, char *argv[])
{

}
