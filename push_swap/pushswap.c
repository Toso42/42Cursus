/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:53:13 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/02 11:31:30 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_small(t_mem *mem)
{
	int	x;

	x = 0;
	ft_findall(mem);
	if (mem->lena < 4)
	{
		ft_three(mem);
		return (0);
	}
	else if (mem->lena < 6)
		ft_five(mem);
	return (1);
}

void	ft_pushswap(t_mem *mem)
{
	if (ft_small(mem) == 0)
		return ;
	if (ft_prep(mem) == 0)
		return ;
	if (mem->lenb > 0)
	{
		ft_tablecreator(mem);
		while (mem->lenb > 0)
		{
			ft_findall(mem);
			ft_tablecreator(mem);
		}
	}
	ft_findall(mem);
	if (mem->minposition <= (mem->lena / 2))
		while (mem->minposition-- > 0)
			ft_rab(mem, 'a', 0);
	else
		while (mem->minposition++ < mem->lena)
			ft_rrab(mem, 'a', 0);
	return ;
}

int	main(int pippo, char **topo)
{
	t_mem	mem;

	if (pippo < 2)
		return (0);
	mem.pippo1 = (pippo - 1);
	ft_populatemem(&mem);
	if (ft_createa(&mem, pippo, topo) == 0)
	{
		ft_freeall(&mem);
		ft_error(&mem);
	}
	if (ft_checkdoubles(&mem) == 0)
	{
		ft_freeall(&mem);
		ft_error(&mem);
	}
	ft_findall(&mem);
	ft_flatit(&mem);
	ft_pushswap(&mem);
	ft_printanswer(&mem);
	ft_freeall(&mem);
	return (0);
}
