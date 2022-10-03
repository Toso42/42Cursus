/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:57:28 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/30 18:59:52 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_mutex
{
	pthread_mutex_t	mugo;
	int				go;
}	t_mutex;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				fork;
}	t_fork;

typedef struct s_philo
{
	int				rules[5];
	int				philo_id;
	pid_t			pid;
	int				meal_counter;
	long long		last_meal;
	long long		initial_time;
	pthread_t		monitor;
	sem_t			*print;
	sem_t			*forks;
	sem_t			*someonedied;
	sem_t			*meal_target;
}	t_philo;

// params: 0 number of philos, 1 ttd, 2 tte, 3 tts, 4 meal target
typedef struct s_box
{
	int				params[5];
	pid_t			*pids;
	t_philo			philo;
	sem_t			*s_print;
	sem_t			*s_forks;
	sem_t			*s_someonedied;
	sem_t			*s_target;
	pthread_t		meal_target;
}	t_box;

//atoi.c
int			is_digit(char **argv, int counter, int inner_counter);
int			ft_atoi(const char *str);
//creation.c
int			create_box(int argc, char **argv, t_box *box, int counter);
int			create_sems(t_box *box, int counter);
int			create_philos(t_box *box, int counter);
//main.c
int			check_go(t_mutex *go);
//process.c
void		*monitor(void *ph);
void		routine(t_philo *philo);
//timing.c
void		ph_wait(int amount);
int			ph_sleep(t_philo *philo);
long long	ms_time(void);
//printer.c
int			ft_print(int pid, char *str, long long now, sem_t *printer);
#endif
