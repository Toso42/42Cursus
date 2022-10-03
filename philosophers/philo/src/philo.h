/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:57:28 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:58:44 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

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
	int				pid;
	int				meal_counter;
	long long		last_meal;
	pthread_mutex_t	meal_m;
	pthread_t		thread;
	t_fork			*lfork;
	t_fork			*rfork;
	t_mutex			*go;
}	t_philo;

// params: 0 number of philos, 1 ttd, 2 tte, 3 tts, 4 meal target
typedef struct s_box
{
	int				params[5];
	t_philo			*philos;
	t_fork			*forks;
	t_mutex			go;
}	t_box;

//actions.c
int			take_fork(t_fork *fork);
void		let_the_forks(t_philo *philo);
int			ph_eat(t_philo *philo);
int			ph_sleep(t_philo *philo);
int			ph_think(t_philo *philo);
//atoi.c
int			is_digit(char **argv, int counter, int inner_counter);
int			ft_atoi(const char *str);
//creation.c
int			create_box(int argc, char **argv, t_box *box, int counter);
void		link_forks(t_philo *philo, t_box *box, int counter);
int			create_forks(t_box *box, int counter);
int			create_philos(t_box *box, int target, int counter);
int			create_mutexes(t_box *box, int counter);
//main.c
int			check_go(t_mutex *go);
//monitor.c
int			monitor_loop(t_box *box, int counter, long long philo_ts,
				int are_fed);
void		monitor(t_box *box, int counter);
//print.c
int			ft_print(int mode, int pid, char *str, void *argument);
//thread.c
void		*routine(t_philo *philo);
//timing.c
void		ph_wait(int amount);
int			ph_sleep(t_philo *philo);
long long	ms_time(void);

#endif
