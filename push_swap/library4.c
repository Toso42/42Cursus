/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:05:14 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 19:41:42 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_freetable(int **table, int size)
{
	int	x;

	x = -1;
	while (++x < size)
	{
		if (table[x])
			free(table[x]);
	}
	if (table)
		free(table);
}

void	ft_newa(t_mem *mem, int a)
{
	int	i;
	int	*newa;

	i = -1;
	newa = (int *)malloc((mem->lena + 1) * sizeof(int));
	while (++i < mem->lena)
	{
		newa[i] = mem->a[i];
	}
	newa[i] = a;
	free(mem->a);
	mem->a = newa;
	mem->lena += 1;
}

void	ft_splitit(t_mem *mem, char *arg)
{
	int		i;
	int		counter;
	char	**newargs;

	newargs = ft_split(mem, arg, ' ');
	counter = sizeof(newargs) / sizeof(newargs[0]);
	i = -1;
	while (++i < mem->argsnumbers)
	{
		ft_newa(mem, ft_atoi(mem, newargs[i]));
		free(newargs[i]);
	}
	free(newargs);
}

int	ft_createa(t_mem *mem, int pippo, char **topo)
{
	int	x;
	int	as;

	as = 0;
	x = -1;
	while (++x < (pippo -1))
	{
		if (ft_checkargv(topo[x + 1]) == 0)
		{
			ft_error(mem);
			return (0);
		}
		else if (ft_checkspace(topo[x + 1]) == 1)
			ft_splitit(mem, topo[x + 1]);
		else
			ft_newa(mem, ft_atoi(mem, topo[x + 1]));
	}
	return (1);
}

void	ft_freeall(t_mem *mem)
{
	if (mem->a)
		free(mem->a);
	if (mem->b)
		free(mem->b);
	if (mem->answer)
		free(mem->answer);
	if (mem->table)
		ft_freetable(mem->table, mem->oldtablesize);
	if (mem->instruction)
		free(mem->instruction);
}
