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

int	ft_print(int mode, int pid, char *str, void *argument)
{
	static int				relay;
	static long long		start_time;
	static pthread_mutex_t	printer;

	if (mode == 0)
	{
		pthread_mutex_init(&printer, NULL);
		start_time = (long long)argument;
		return (0);
	}
	pthread_mutex_lock(&printer);
	if (mode == 1 && relay == 0)
		printf("%lld %d %s\n", (ms_time() - start_time), pid, str);
	else if (mode == 2 && relay == 0)
	{
		relay = 1;
		printf("%lld %d %s\n", (ms_time() - start_time), pid, str);
	}
	pthread_mutex_unlock(&printer);
	if (mode == -1)
		pthread_mutex_destroy(&printer);
	return (relay);
}
