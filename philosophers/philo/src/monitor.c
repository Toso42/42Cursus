/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:54:58 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:57:04 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_loop(t_box *box, int counter, long long philo_ts, int are_fed)
{
	while (++counter < box->params[0])
	{
		pthread_mutex_lock(&box->philos[counter].meal_m);
		philo_ts = box->philos[counter].last_meal;
		pthread_mutex_unlock(&box->philos[counter].meal_m);
		if ((ms_time() - philo_ts) > box->params[1])
		{
			ft_print(2, (counter + 1), "is dead", NULL);
			return (EXIT_FAILURE);
		}
		if (box->params[4] > 0 && box->philos[counter].meal_counter
			>= (box->params[4]))
			are_fed++;
		if (are_fed == box->params[0])
		{
			usleep(1000);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

void	monitor(t_box *box, int counter)
{
	long long	philo_ts;

	while (1)
	{
		if (monitor_loop(box, counter, philo_ts, 0))
			break ;
		counter = -1;
	}
}
