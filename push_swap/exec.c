/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:19 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 18:51:40 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_ex1(t_mem *mem, int row)
{
	while (mem->table[row][1] > 0 && mem->table[row][3] > 0)
	{
		ft_rr(mem);
		mem->table[row][1] -= 1;
		mem->table[row][3] -= 1;
	}
	while (mem->table[row][1] > 0)
	{
		ft_rab(mem, 'a', 0);
		mem->table[row][1] -= 1;
	}
	while (mem->table[row][3] > 0)
	{
		ft_rab(mem, 'b', 0);
		mem->table[row][3] -= 1;
	}
}

void	ft_ex2(t_mem *mem, int row)
{
	while (mem->table[row][2] > 0 && mem->table[row][4] > 0)
	{
		ft_rrr(mem);
		mem->table[row][2] -= 1;
		mem->table[row][4] -= 1;
	}
	while (mem->table[row][2] > 0)
	{
		ft_rrab(mem, 'a', 0);
		mem->table[row][2] -= 1;
	}
	while (mem->table[row][4] > 0)
	{
		ft_rrab(mem, 'b', 0);
		mem->table[row][4] -= 1;
	}
}

void	ft_ex3(t_mem *mem, int row)
{
	while (mem->table[row][1] > 0)
	{
		ft_rab(mem, 'a', 0);
		mem->table[row][1] -= 1;
	}
	while (mem->table[row][4] > 0)
	{
		ft_rrab(mem, 'b', 0);
		mem->table[row][4] -= 1;
	}
}

void	ft_ex4(t_mem *mem, int row)
{
	while (mem->table[row][2] > 0)
	{
		ft_rrab(mem, 'a', 0);
		mem->table[row][2] -= 1;
	}
	while (mem->table[row][3] > 0)
	{
		ft_rab(mem, 'b', 0);
		mem->table[row][3] -= 1;
	}
}

void	ft_exec(t_mem *mem)
{
	int	t;
	int	row;

	row = mem->minrow;
	t = mem->table[row][5];
	if (t == 1)
		ft_ex1(mem, row);
	else if (t == 2)
		ft_ex2(mem, row);
	else if (t == 3)
		ft_ex3(mem, row);
	else if (t == 4)
		ft_ex4(mem, row);
	ft_pab(mem, 'a');
}
