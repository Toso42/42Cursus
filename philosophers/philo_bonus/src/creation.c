/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:40:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/30 18:42:25 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static sem_t	*sem_in(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

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
	return (EXIT_SUCCESS);
}

int	create_sems(t_box *box, int counter)
{
	box->s_print = sem_in("/print", 1);
	box->s_forks = sem_in("/forks", box->params[0]);
	box->s_someonedied = sem_in("/someonedied", 0);
	box->s_target = sem_in("/s_target", 0);
	return (EXIT_SUCCESS);
}

int	create_philos(t_box *box, int counter)
{
	box->philo.rules[0] = box->params[0];
	box->philo.rules[1] = box->params[1];
	box->philo.rules[2] = box->params[2];
	box->philo.rules[3] = box->params[3];
	box->philo.rules[4] = box->params[4];
	box->philo.meal_counter = 0;
	box->philo.last_meal = 0;
	box->philo.philo_id = counter + 1;
	box->philo.print = box->s_print;
	box->philo.forks = box->s_forks;
	box->philo.someonedied = box->s_someonedied;
	box->philo.meal_target = box->s_target;
	return (EXIT_SUCCESS);
}
