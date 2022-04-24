/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:41:29 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 19:49:37 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_add(t_mem *mem, char what)
{
	int	x;
	int	*swap;

	swap = NULL;
	x = 0;
	ft_addinitializer(mem, what);
	if (mem->len == 0)
		return ;
	mem->len[0] += 1;
	swap = ft_calloc(mem->len[0], sizeof(int));
	swap[0] = (*mem->argfrom)[0];
	while (++x < mem->len[0])
		swap[x] = (*mem->argto)[x - 1];
	free(*mem->argto);
	(*mem->argto) = swap;
}

void	ft_rem(t_mem *mem, char what)
{
	int	x;
	int	*swap;

	swap = NULL;
	ft_rabsinitializer(mem, what);
	if (mem->len == 0)
		return ;
	x = -1;
	mem->len[0] -= 1;
	swap = ft_calloc(((int)mem->len[0]), sizeof(int));
	while (++x < mem->len[0])
		swap[x] = (*mem->parg)[x + 1];
	free(*mem->parg);
	(*mem->parg) = swap;
}

void	ft_ss(t_mem *mem)
{
	ft_sab(mem, 'a', 1);
	ft_sab(mem, 'b', 1);
	ft_answer(mem, "ss\n", 3);
}

void	ft_rr(t_mem *mem)
{
	ft_rab(mem, 'a', 1);
	ft_rab(mem, 'b', 1);
	ft_answer(mem, "rr\n", 3);
}

void	ft_rrr(t_mem *mem)
{
	ft_rrab(mem, 'a', 1);
	ft_rrab(mem, 'b', 1);
	ft_answer(mem, "rrr\n", 4);
}
