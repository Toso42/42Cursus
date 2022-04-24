/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:07:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 16:53:00 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_firstliss(t_mem *mem)
{
	int	x;

	x = -1;
	while (++x < mem->lena)
		if (ft_findincomb(mem, mem->a[x]) == 0)
			break ;
	mem->ras = x;
	x = mem->lena + 1;
	while (--x > 0)
		if (ft_findincomb(mem, mem->a[x - 1]) == 0)
			break ;
	mem->rras = (mem->lena - x);
}

void	ft_flatit(t_mem *mem)
{
	int	x;
	int	counter;
	int	*newa;

	counter = mem->lena;
	mem->firstasize = mem->lena;
	x = -1;
	newa = (int *)malloc(mem->lena * sizeof(int));
	while (++x < mem->lena)
	{
		newa[x] = mem->a[x];
	}
	x = -1;
	ft_findmin(mem, 'a');
	ft_findmax(mem, 'a');
	while (++x < (mem->lena - 1))
	{
		newa[mem->maxposition] = counter;
		mem->a[mem->maxposition] = -2147483647;
		counter--;
		ft_findmax(mem, 'a');
	}
	newa[mem->minposition] = 1;
	free(mem->a);
	mem->a = newa;
}

void	ft_freeargs(t_mem *mem)
{
	int	x;

	x = 0;
	while (mem->argsnumbers > 0)
	{
		free(mem->splittedargs[x]);
		x++;
		mem->argsnumbers--;
	}
	free(mem->splittedargs);
}

void	ft_createstack(t_mem *mem, char what)
{
	if (what == 'a')
		mem->a = ft_calloc((mem->lena + 1), sizeof(int));
	else if (what == 'b')
		mem->b = ft_calloc((mem->lenb + 1), sizeof(int));
}

void	ft_printanswer(t_mem *mem)
{
	int	x;

	x = -1;
	while (mem->answer[++x])
		write(1, &mem->answer[x], 1);
}
