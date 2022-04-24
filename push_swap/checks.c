/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:33:01 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 16:52:01 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_checkspace(char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == 32)
			return (1);
	}
	return (0);
}

int	ft_checkargv(char *string)
{
	int	x;

	x = -1;
	while (string[++x] != 0)
	{
		if (!((string[x] > 47 && string[x] < 58) || string[x] == 32
				|| string[x] == 43 || string[x] == 45))
			return (0);
	}
	return (1);
}

int	ft_checkrep(int what, int *in, int sizeofin)
{
	int	x;

	x = -1;
	while (++x < sizeofin)
	{
		if (in[x] == what)
			return (1);
	}
	return (0);
}

void	ft_checkfinisher(t_mem *mem, int z, int x, int y)
{
	mem->swap = (int *)malloc((y + 1) * sizeof(int));
	while (++z < y)
		mem->swap[z] = mem->store[z];
	mem->swap[z] = mem->a[x];
	z = -1;
	free(mem->store);
	mem->store = mem->swap;
}

int	ft_checkdoubles(t_mem *mem)
{
	int	x;
	int	y;
	int	z;

	z = -1;
	y = 0;
	x = 0;
	mem->store = (int *)malloc(1 * sizeof(int));
	mem->store[y] = mem->a[x];
	while (++x < mem->lena)
	{
		y++;
		if (ft_checkrep(mem->a[x], mem->store, y) == 0)
			ft_checkfinisher(mem, z, x, y);
		else
			return (0);
	}
	free(mem->store);
	return (1);
}
