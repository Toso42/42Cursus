/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillrra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:15:36 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 18:22:07 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_fillrraj0(t_mem *mem, int *i, int *j, int *k)
{
	if (mem->a[0] == mem->min)
	{
		if (mem->b[i[0]] < mem->a[j[0]])
		{
			mem->table[i[0]][2] = k[0];
			return (1);
		}
	}
	else if (mem->a[mem->lena - 1] != mem->min)
	{
		if (mem->b[i[0]] > mem->a[mem->lena - 1] && mem->b[i[0]] < mem->a[j[0]])
		{
			mem->table[i[0]][2] = k[0];
			return (1);
		}
	}
	return (0);
}

int	ft_fillrraj1(t_mem *mem, int *i, int *j, int *k)
{
	if (mem->a[j[0]] == mem->min)
	{
		if (mem->b[i[0]] > mem->a[j[0] - 1])
		{
			mem->table[i[0]][2] = k[0];
			return (1);
		}
	}
	else if (mem->a[j[0]] != mem->min)
	{
		if (mem->b[i[0]] > mem->a[j[0] - 1] && mem->b[i[0]] < mem->a[j[0]])
		{
			mem->table[i[0]][2] = k[0];
			return (1);
		}
	}
	return (0);
}

void	ft_fillrra(t_mem *mem)
{
	int	i;
	int	j;
	int	k;

	j = (mem->lena);
	i = -1;
	k = 0;
	while (++i < mem->lenb)
	{
		while (--j > 0)
		{
			k++;
			if (j == 0)
			{
				if (ft_fillrraj0(mem, &i, &j, &k) == 1)
					break ;
			}
			else if (j > 0)
				if (ft_fillrraj1(mem, &i, &j, &k) == 1)
					break ;
		}
		k = 0;
		j = mem->lena;
	}
}
