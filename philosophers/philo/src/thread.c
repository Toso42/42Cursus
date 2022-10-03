/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:59:31 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:59:54 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	compete(t_philo *philo)
{
	while (1)
	{
		while (take_fork(philo->lfork))
			;
		if (ft_print(1, philo->pid, "has taken a fork", NULL))
			break ;
		while (take_fork(philo->rfork))
			;
		if (ft_print(1, philo->pid, "has taken a fork", NULL))
			break ;
		if (ph_eat(philo)
			|| ph_sleep(philo)
			|| ph_think(philo))
			break ;
	}
}

void	*routine(t_philo *philo)
{
	while (!check_go(philo->go))
	{
		pthread_mutex_lock(&philo->meal_m);
		philo->last_meal = ms_time();
		pthread_mutex_unlock(&philo->meal_m);
	}
	if (philo->pid % 2)
		usleep(500);
	compete(philo);
	return (EXIT_SUCCESS);
}
