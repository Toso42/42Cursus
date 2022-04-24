/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:11:44 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 15:15:22 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_fillraj0(t_mem *mem, int *i, int *j)
{
	if (mem->a[(mem->lena - 1)] == mem->min)
	{
		if (mem->b[i[0]] < mem->a[j[0]] || (mem->b[i[0]]
				== mem->min2 && mem->b[i[0]] < mem->a[j[0]]))
		{
			mem->table[i[0]][1] = j[0];
			return (1);
		}
	}
	else
	{
		if (mem->b[i[0]] > mem->a[mem->lena - 1] && mem->b[i[0]]
			< mem->a[j[0]])
		{
			mem->table[i[0]][1] = j[0];
			return (1);
		}
	}
	return (0);
}

int	ft_fillraj1(t_mem *mem, int *i, int *j)
{
	if (mem->a[j[0]] == mem->min)
	{
		if (mem->b[i[0]] > mem->a[j[0] - 1] || (mem->b[i[0]]
				== mem->min2 && mem->b[i[0]] < mem->a[j[0]]))
		{
			mem->table[i[0]][1] = j[0];
			return (1);
		}
	}
	else
	{
		if (mem->b[i[0]] > mem->a[j[0] - 1] && mem->b[i[0]] < mem->a[j[0]])
		{
			mem->table[i[0]][1] = j[0];
			return (1);
		}
	}
	return (0);
}

void	ft_fillra(t_mem *mem)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (++i < mem->lenb)
	{
		while (++j < mem->lena)
		{
			if (j == 0)
			{
				if (ft_fillraj0(mem, &i, &j) == 1)
					break ;
			}
			else if (j > 0)
			{
				if (ft_fillraj1(mem, &i, &j) == 1)
					break ;
			}
		}
		j = -1;
	}
}
