/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:58:53 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/09/24 20:59:21 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(int pid, char *str, long long now, sem_t *printer)
{
	fflush(stdout);
	sem_wait(printer);
	printf("%lld %d %s\n", now, pid, str);
	fflush(stdout);
	sem_post(printer);
	return (0);
}

// int	ft_print(int mode, int pid, char *str, void *argument)
// {
// 	static int				relay;
// 	static long long		start_time;
// 	sem_t					*printer;

// 	fflush(stdout);
// //	usleep(50);
// 	if (mode == -1)
// 	{
// 		start_time = (long long)argument;
// 		relay = 0;
// 		return (0);
// 	}
// 	else if (mode == 0)
// 	{
// 		printer = (sem_t *)argument;
// 		return (0);
// 	}
// 	else
// 	{
// 		sem_wait(printer);
// 		printf("%lld %d %s\n", (ms_time() - start_time), pid, str);
// 		fflush(stdout);
// 		sem_post(printer);
// 	}
// 	return (relay);
// }
