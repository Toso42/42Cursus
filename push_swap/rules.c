/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:43:57 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 19:32:20 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_rabsinitializer(t_mem *mem, char what)
{
	if (what == 'a')
	{
		mem->parg = &mem->a;
		mem->len = &mem->lena;
	}
	else if (what == 'b')
	{
		mem->parg = &mem->b;
		mem->len = &mem->lenb;
	}
}

void	ft_sab(t_mem *mem, char what, int mode)
{
	int	j;

	if (what == 'a')
	{
		mem->arg = mem->a;
		mem->len = &mem->lena;
		if (mem->len[0] < 2)
			return ;
		if (mode != 1)
			ft_answer(mem, "sa\n", 3);
	}
	else if (what == 'b')
	{
		mem->arg = mem->b;
		mem->len = &mem->lenb;
		if (mem->len[0] < 2)
			return ;
		if (mode != 1)
			ft_answer(mem, "sb\n", 3);
	}
	j = mem->arg[0];
	mem->arg[0] = mem->arg[1];
	mem->arg[1] = j;
}

void	ft_pab(t_mem *mem, char what)
{
	if (what == 'b' && mem->lena > 0)
	{
		if (!mem->b)
			ft_createstack(mem, 'b');
		ft_add(mem, 'b');
		ft_rem(mem, 'a');
		ft_answer(mem, "pb\n", 3);
	}
	if (what == 'a' && mem->lenb > 0)
	{
		if (!mem->a)
			ft_createstack(mem, 'a');
		ft_add(mem, 'a');
		ft_rem(mem, 'b');
		ft_answer(mem, "pa\n", 3);
	}
}

void	ft_rab(t_mem *mem, char what, int mode)
{
	int	x;
	int	*swap;

	swap = NULL;
	x = -1;
	ft_rabsinitializer(mem, what);
	if (!mem->len)
		return ;
	swap = ft_calloc(((int)mem->len[0]), sizeof(int));
	while (++x < (mem->len[0] - 1))
		swap[x] = (*mem->parg)[x + 1];
	swap[x] = (*mem->parg)[0];
	free(*mem->parg);
	(*mem->parg) = swap;
	if (mode != 1)
	{
		if (what == 'a')
			ft_answer(mem, "ra\n", 3);
		else
			ft_answer(mem, "rb\n", 3);
	}
}

void	ft_rrab(t_mem *mem, char what, int mode)
{
	int	x;
	int	*swap;

	swap = NULL;
	x = 0;
	ft_rabsinitializer(mem, what);
	if (!mem->len)
		return ;
	swap = ft_calloc(((int)mem->len[0]), sizeof(int));
	swap[x] = (*mem->parg)[(mem->len[0] - 1)];
	while (++x < (mem->len[0]))
		swap[x] = (*mem->parg)[x - 1];
	free(*mem->parg);
	(*mem->parg) = swap;
	if (mode != 1)
	{
		if (what == 'a')
			ft_answer(mem, "rra\n", 4);
		else
			ft_answer(mem, "rrb\n", 4);
	}
}
