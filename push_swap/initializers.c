/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:16:01 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 17:07:50 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_addinitializer(t_mem *mem, char what)
{
	if (what == 'a')
	{
		mem->argfrom = &mem->b;
		mem->argto = &mem->a;
		mem->len = &mem->lena;
	}
	else if (what == 'b')
	{
		mem->argfrom = &mem->a;
		mem->argto = &mem->b;
		mem->len = &mem->lenb;
	}
}

void	ft_findmaxinitializer(t_mem *mem, char what)
{
	if (what == 'a')
	{
		mem->arg = mem->a;
		mem->len = &mem->lena;
		mem->pmax = &mem->max;
		mem->pmaxposition = &mem->maxposition;
	}
	else if (what == 'b')
	{
		mem->arg = mem->b;
		mem->len = &mem->lenb;
		mem->pmax = &mem->max2;
		mem->pmaxposition = &mem->max2position;
	}
}

void	ft_findmininitializer(t_mem *mem, char what)
{
	if (what == 'a')
	{
		mem->arg = mem->a;
		mem->len = &mem->lena;
		mem->pmin = &mem->min;
		mem->pminposition = &mem->minposition;
	}
	else if (what == 'b')
	{
		mem->arg = mem->b;
		mem->len = &mem->lenb;
		mem->pmin = &mem->min2;
		mem->pminposition = &mem->min2position;
	}
}

void	ft_populatemem2(t_mem *mem)
{
	mem->argsnumbers = 0;
	mem->max2 = 0;
	mem->max2position = 0;
	mem->min2 = 0;
	mem->min2position = 0;
	mem->instruction = NULL;
	mem->arg = NULL;
	mem->len = NULL;
}

void	ft_populatemem(t_mem *mem)
{
	mem->pmax = NULL;
	mem->pmaxposition = NULL;
	mem->pmin = NULL;
	mem->pminposition = NULL;
	mem->table = NULL;
	mem->a = NULL;
	mem->a = ft_calloc(mem->pippo1, sizeof(int));
	mem->lena = 0;
	mem->lenb = 0;
	mem->b = NULL;
	mem->min = 0;
	mem->minposition = 0;
	mem->minrow = 0;
	mem->oldtablesize = 0;
	mem->firstasize = 0;
	mem->answerlen = 0;
	mem->answer = (char *)malloc(1 * sizeof(char));
	mem->answer[0] = '\0';
	mem->splittedargs = NULL;
	ft_populatemem2(mem);
}
