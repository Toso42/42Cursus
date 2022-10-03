/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:41:11 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:54:50 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_go(t_mutex *go)
{
	pthread_mutex_lock(&go->mugo);
	if (go->go)
	{
		pthread_mutex_unlock(&go->mugo);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&go->mugo);
	return (EXIT_SUCCESS);
}

int	set_go(t_box *box, int counter, long long start_timer)
{
	start_timer = ms_time();
	while (++counter < box->params[0])
	{
		box->philos[counter].last_meal = start_timer;
		pthread_create(&box->philos[counter].thread, NULL, (void *)routine,
			&box->philos[counter]);
		pthread_detach(box->philos[counter].thread);
	}
	pthread_mutex_lock(&box->go.mugo);
	box->go.go = 1;
	ft_print(0, -1, NULL, (void *)start_timer);
	pthread_mutex_unlock(&box->go.mugo);
	monitor(box, -1);
	counter = -1;
	while (++counter < box->params[0])
		pthread_join(box->philos[counter].thread, NULL);
	return (EXIT_SUCCESS);
}

void	free_all(t_box *box, int counter)
{
	while (++counter < box->params[0])
	{
		pthread_mutex_destroy(&box->philos[counter].meal_m);
		pthread_mutex_destroy(&box->forks[counter].mutex);
	}
	pthread_mutex_destroy(&box->go.mugo);
	free(box->forks);
	free(box->philos);
	ft_print(-1, 0, NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_box	box;

	if (argc < 5 || argc > 6
		|| create_box(argc, argv, &box, 0)
		|| create_forks(&box, -1)
		|| create_philos(&box, box.params[0], -1)
		|| create_mutexes(&box, -1)
		|| set_go(&box, -1, 0LL))
		return (EXIT_FAILURE);
	free_all(&box, -1);
	return (EXIT_SUCCESS);
}
