/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablecalc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:16:57 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 14:40:38 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_findmintable(t_mem *mem)
{
	int	i;

	i = 0;
	mem->minrow = 0;
	while (++i < mem->lenb)
	{
		if (mem->table[i][0] < mem->table[mem->minrow][0])
			mem->minrow = i;
	}
}

void	ft_tablecalc2(t_mem *mem)
{
	int	i;
	int	min;

	i = -1;
	while (++i < mem->lenb)
	{
		min = mem->table[i][1] + mem->table[i][4];
		if (min < mem->table[i][0])
		{
			mem->table[i][0] = min;
			mem->table[i][5] = 3;
		}
	}
	i = -1;
	while (++i < mem->lenb)
	{
		min = mem->table[i][2] + mem->table[i][3];
		if (min < mem->table[i][0])
		{
			mem->table[i][0] = min;
			mem->table[i][5] = 4;
		}
	}
}

void	ft_tablecalc(t_mem *mem)
{
	int	min;
	int	i;

	i = -1;
	while (++i < mem->lenb)
	{
		min = mem->table[i][1];
		if (min < mem->table[i][3])
			min = mem->table[i][3];
		mem->table[i][0] = min;
		mem->table[i][5] = 1;
	}
	i = -1;
	while (++i < mem->lenb)
	{
		min = mem->table[i][2];
		if (min < mem->table[i][4])
			min = mem->table[i][4];
		if (min < mem->table[i][0])
		{
			mem->table[i][0] = min;
			mem->table[i][5] = 2;
		}
	}
	ft_tablecalc2(mem);
}
