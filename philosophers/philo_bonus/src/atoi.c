/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:39:09 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:40:14 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char **argv, int counter, int inner_counter)
{
	while (argv[++counter] != NULL)
	{
		while (argv[counter][++inner_counter] != '\0')
		{
			if (argv[counter][inner_counter] != '+'
				&& argv[counter][inner_counter] != '-'
				&& (argv[counter][inner_counter] < 48
				|| argv[counter][inner_counter] > 57))
				return (EXIT_FAILURE);
			if (argv[counter][inner_counter] == '+'
			|| argv[counter][inner_counter] == '-')
			{
				if (!(argv[counter][inner_counter + 1] >= 48)
					|| !(argv[counter][inner_counter + 1] <= 57))
					return (EXIT_FAILURE);
			}
		}
		inner_counter = -1;
	}
	return (EXIT_SUCCESS);
}

static int	long_max(int j, int x)
{
	int	y;

	y = 0;
	if (j >= 19 && x == 1)
		y = -1;
	if (j >= 19 && x == -1)
		y = 0;
	return (y);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	y;
	int	j;

	y = 0;
	x = 1;
	j = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			x *= -1;
		str++;
	}
	while (*str <= 57 && *str >= 48)
	{
		y = (y * 10) + ((*str - 48) % 10);
		str++;
		j++;
	}
	y *= x;
	if (j >= 19)
		return (long_max(j, x));
	return (y);
}
