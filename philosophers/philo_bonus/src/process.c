/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:43:08 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/30 19:01:11 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*monitor(void *ph)
{
	long long	timer;
	t_philo		*philo;

	philo = ph;
	while (1)
	{
		sem_wait(philo->print);
		if (ms_time() - philo->last_meal > philo->rules[1])
		{
			printf("%lld %d died\n",
				(ms_time() - philo->initial_time), philo->philo_id);
			sem_post(philo->someonedied);
			return (EXIT_SUCCESS);
		}
		sem_post(philo->print);
		if (philo->rules[4] > 0 && philo->meal_counter >= philo->rules[4])
		{
			sem_post(philo->meal_target);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}

void	routine(t_philo *philo)
{
	pthread_create(&philo->monitor, NULL, (void *)monitor, philo);
	while (1)
	{
		sem_wait(philo->forks);
		ft_print(philo->philo_id, "has taken a fork",
			(ms_time() - philo->initial_time), philo->print);
		sem_wait(philo->forks);
		ft_print(philo->philo_id, "has taken a fork",
			(ms_time() - philo->initial_time), philo->print);
		philo->last_meal = ms_time();
		ft_print(philo->philo_id, "is eating",
			(ms_time() - philo->initial_time), philo->print);
		philo->meal_counter += 1;
		ph_wait(philo->rules[2]);
		sem_post(philo->forks);
		sem_post(philo->forks);
		ft_print(philo->philo_id, "is sleeping",
			(ms_time() - philo->initial_time), philo->print);
		ph_wait(philo->rules[3]);
		ft_print(philo->philo_id, "is thinking",
			(ms_time() - philo->initial_time), philo->print);
	}
}
