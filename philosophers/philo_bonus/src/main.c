/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:45:55 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/30 18:58:35 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_target(t_box *box)
{
	int	counter;

	counter = -1;
	while (++counter < box->params[0])
		sem_wait(box->s_target);
	sem_post(box->s_someonedied);
}

void	spawn_philos(t_box *box, pid_t *pids, int counter)
{
	while (++counter < box->params[0])
	{
		pids[counter] = fork();
		if (pids[counter] == 0)
		{
			box->philo.philo_id = counter + 1;
			routine(&box->philo);
		}
	}
}

int	fork_it(t_box *box, int counter)
{
	long long	start_timer;
	pid_t		*pids;
	pid_t		target_searcher;

	pids = malloc(sizeof(pid_t) * box->params[0]);
	target_searcher = 1;
	box->pids = pids;
	start_timer = ms_time();
	box->philo.last_meal = start_timer;
	box->philo.initial_time = start_timer;
	spawn_philos(box, pids, counter);
	target_searcher = fork();
	if (target_searcher == 0)
		wait_target(box);
	else
	{
		counter = -1;
		sem_wait(box->s_someonedied);
		while (++counter < box->params[0])
			kill(pids[counter], SIGKILL);
	}
	free(pids);
	return (EXIT_SUCCESS);
}

void	close_sems(t_box *box)
{
	sem_close(box->s_forks);
	sem_close(box->s_print);
	sem_close(box->s_someonedied);
	sem_close(box->s_target);
}

int	main(int argc, char **argv)
{
	t_box	box;

	if (argc < 5 || argc > 6
		|| create_box(argc, argv, &box, 0)
		|| create_sems(&box, -1)
		|| create_philos(&box, -1)
		|| fork_it(&box, -1))
		return (EXIT_FAILURE);
	close_sems(&box);
	return (EXIT_SUCCESS);
}
