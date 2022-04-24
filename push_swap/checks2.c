/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:18:19 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 19:44:22 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_findmax(t_mem *mem, char what)
{
	int	x;

	x = -1;
	ft_findmaxinitializer(mem, what);
	mem->pmax[0] = mem->arg[0];
	mem->pmaxposition[0] = 0;
	while (++x < mem->len[0])
	{
		if (mem->arg[x] > mem->pmax[0])
		{
			mem->pmax[0] = mem->arg[x];
			mem->pmaxposition[0] = x;
		}
	}
}

void	ft_findmin(t_mem *mem, char what)
{
	int	x;

	x = -1;
	ft_findmininitializer(mem, what);
	mem->pmin[0] = mem->arg[0];
	mem->pminposition[0] = 0;
	while (++x < mem->len[0])
	{
		if (mem->arg[x] < mem->pmin[0])
		{
			mem->pmin[0] = mem->arg[x];
			mem->pminposition[0] = x;
		}
	}
}

void	ft_findall(t_mem *mem)
{
	if (mem->lena > 0)
	{
		ft_findmax(mem, 'a');
		ft_findmin(mem, 'a');
	}
	if (mem->lenb > 0)
	{
		ft_findmax(mem, 'b');
		ft_findmin(mem, 'b');
	}
}

void	ft_checkmalloc(t_mem *mem, void *ptr)
{
	if (ptr == NULL)
		ft_error(mem);
}

void	ft_error(t_mem *mem)
{
	write(2, "Error\n", 6);
	mem = 0;
	exit(1);
}
