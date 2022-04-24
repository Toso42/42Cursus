/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:59:46 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 15:46:41 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_ko(t_mem *mem)
{
	write(1, "KO\n", 3);
	ft_freeall(mem);
	exit (1);
}

int	ft_compare(char *instruction, char *target)
{
	int	x;

	x = -1;
	while (instruction[++x] != 0)
	{
		if (instruction[x] != target[x])
			return (0);
	}
	return (1);
}

int	ft_checkerstarter(t_mem *mem, int pippo, char **topo)
{
	mem->pippo1 = (pippo - 1);
	mem->arg = NULL;
	mem->len = NULL;
	ft_populatemem(mem);
	ft_createstack(mem, 'b');
	if (ft_createa(mem, pippo, topo) == 0)
	{
		ft_freeall(mem);
		ft_error(mem);
		return (0);
	}
	if (ft_checkdoubles(mem) == 0)
	{
		ft_error(mem);
		ft_freeall(mem);
		return (0);
	}
	return (1);
}
