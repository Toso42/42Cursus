/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:40:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:41:00 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	create_box(int argc, char **argv, t_box *box, int counter)
{
	while (++counter < argc)
	{
		if (is_digit(argv, 0, -1) || ft_atoi(argv[counter]) < 0
			|| ft_atoi(argv[counter]) > INT32_MAX || ft_atoi(argv[1]) <= 0)
			return (EXIT_FAILURE);
	}
	box->params[0] = ft_atoi(argv[1]);
	box->params[1] = ft_atoi(argv[2]);
	box->params[2] = ft_atoi(argv[3]);
	box->params[3] = ft_atoi(argv[4]);
	if (argc == 6)
		box->params[4] = ft_atoi(argv[5]);
	else
		box->params[4] = -1;
	box->philos = NULL;
	box->forks = NULL;
	return (EXIT_SUCCESS);
}

void	link_forks(t_philo *philo, t_box *box, int counter)
{
	if (counter == 0)
	{
		box->philos[counter].lfork = &box->forks[box->params[0] - 1];
		box->philos[counter].rfork = &box->forks[counter];
	}
	else
	{
		box->philos[counter].lfork = &box->forks[counter - 1];
		box->philos[counter].rfork = &box->forks[counter];
	}
}

int	create_forks(t_box *box, int counter)
{
	box->forks = malloc(sizeof(t_fork) * box->params[0]);
	if (!box->forks)
		return (EXIT_FAILURE);
	while (++counter < box->params[0])
	{
		pthread_mutex_init(&box->forks[counter].mutex, NULL);
		box->forks[counter].fork = 0;
	}
	return (EXIT_SUCCESS);
}

int	create_philos(t_box *box, int target, int counter)
{
	box->philos = malloc(sizeof(t_philo) * target);
	if (!box->philos)
		return (EXIT_FAILURE);
	while (++counter < target)
	{
		box->philos[counter].rules[0] = box->params[0];
		box->philos[counter].rules[1] = box->params[1];
		box->philos[counter].rules[2] = box->params[2];
		box->philos[counter].rules[3] = box->params[3];
		box->philos[counter].rules[4] = box->params[4];
		box->philos[counter].pid = counter + 1;
		box->philos[counter].meal_counter = 0;
		box->philos[counter].last_meal = 0;
		link_forks(&box->philos[counter], box, counter);
		box->philos[counter].go = &box->go;
	}
	return (EXIT_SUCCESS);
}

int	create_mutexes(t_box *box, int counter)
{
	while (++counter < box->params[0])
	{
		pthread_mutex_init(&box->philos[counter].meal_m, NULL);
	}
	pthread_mutex_init(&box->go.mugo, NULL);
	box->go.go = 0;
	return (EXIT_SUCCESS);
}
