/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:49:30 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/23 17:30:36 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

static void	ft_error(void)
{
	ft_printf("error");
	exit(EXIT_FAILURE);
}

static int	ft_sendout(siginfo_t *sender, int *x, int *toprint)
{
	kill(sender->si_pid, SIGUSR1);
	ft_printf("\n-------END OF MESSAGE @%d | OUT sent-------\n-Next:-\n\n",
		getpid());
	x[0] = 0;
	toprint[0] = 0;
	return (EXIT_SUCCESS);
}

static void	ft_wilco(int signal, siginfo_t *sender, void *old)
{
	static int	x;
	static int	toprint;

	old = NULL;
	if (x == 7)
	{
		if (signal == SIGUSR2)
			toprint += 1;
		else if (signal == SIGUSR1 && toprint == 0)
			if (ft_sendout(sender, &x, &toprint) == EXIT_SUCCESS)
				return ;
		ft_printf("%c", (char)toprint);
		x = 0;
		toprint = 0;
	}
	else
	{
		if (signal == SIGUSR2)
			toprint += 1;
		toprint <<= 1;
		x++;
	}
}

int	main(void)
{
	struct sigaction	listener;

	listener.sa_sigaction = &ft_wilco;
	listener.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &listener, NULL) == -1 || sigaction(SIGUSR2,
			&listener, NULL) == -1)
		ft_error();
	ft_printf(" I'm listening at [%d]\n", getpid());
	while (1)
		;
	exit(EXIT_SUCCESS);
}
