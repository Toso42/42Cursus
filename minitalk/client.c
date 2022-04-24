/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:52:22 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/23 17:29:26 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	ft_roger(int signal, siginfo_t *sender, void *old)
{
	old = NULL;
	if (signal == SIGUSR1)
	{
		sender = NULL;
		ft_printf("\n OUT Message Received: OUT's Client executed\n");
		exit(0);
	}
}

static void	ft_over(int serverpid)
{
	int	x;

	x = 8;
	while (x-- > 0)
	{
		kill(serverpid, SIGUSR1);
		usleep(15);
	}
	ft_printf("Message sent @ %d, Do You Read?\n", serverpid);
}

void	ft_sendchar(int serverpid, char tosend)
{
	int	bits;

	bits = 8;
	while (bits-- > 0)
	{
		if (tosend >> bits & 1)
			kill(serverpid, SIGUSR2);
		else
			kill(serverpid, SIGUSR1);
		usleep(20);
	}
}

void	ft_sendstring(int serverpid, char **topo)
{
	int	x;

	x = -1;
	while (topo[2][++x] != 0)
	{
		ft_sendchar(serverpid, topo[2][x]);
		usleep(40);
	}
	ft_over(serverpid);
}

int	main(int pippo, char **topo)
{
	int					serverpid;
	struct sigaction	listener;

	listener.sa_sigaction = &ft_roger;
	listener.sa_flags = 0;
	sigaction(SIGUSR1, &listener, NULL);
	if (pippo != 3)
	{
		ft_printf("\nInput Error, Please type: .\\client <address> \"string\" \n");
		exit(1);
	}
	serverpid = ft_atoi(topo[1]);
	ft_sendstring(serverpid, topo);
	while (1)
		;
	exit(0);
}
