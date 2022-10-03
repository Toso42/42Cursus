/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:00:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 21:00:27 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_wait(int amount)
{
	long long	time;

	time = ms_time();
	usleep(amount * 1000 - 20000);
	while (ms_time() < time + amount)
		usleep(50);
}

int	ph_sleep(t_philo *philo)
{
	if (ft_print(1, philo->pid, "is sleeping", NULL))
		return (EXIT_FAILURE);
	ph_wait(philo->rules[3]);
	return (EXIT_SUCCESS);
}

long long	ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}
