/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:38:20 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:38:58 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (fork->fork)
	{
		pthread_mutex_unlock(&fork->mutex);
		return (EXIT_FAILURE);
	}
	fork->fork = 1;
	pthread_mutex_unlock(&fork->mutex);
	return (EXIT_SUCCESS);
}

void	let_the_forks(t_philo *philo)
{
	t_fork	*left;
	t_fork	*right;

	left = philo->lfork;
	right = philo->rfork;
	pthread_mutex_lock(&left->mutex);
	left->fork = 0;
	pthread_mutex_unlock(&left->mutex);
	pthread_mutex_lock(&right->mutex);
	right->fork = 0;
	pthread_mutex_unlock(&right->mutex);
}

int	ph_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_m);
	philo->last_meal = ms_time();
	pthread_mutex_unlock(&philo->meal_m);
	if (ft_print(1, philo->pid, "is eating", NULL))
		return (EXIT_FAILURE);
	ph_wait(philo->rules[2]);
	pthread_mutex_lock(&philo->meal_m);
	philo->meal_counter += 1;
	pthread_mutex_unlock(&philo->meal_m);
	let_the_forks(philo);
	return (EXIT_SUCCESS);
}

int	ph_think(t_philo *philo)
{
	if (ft_print(1, philo->pid, "is thinking", NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
