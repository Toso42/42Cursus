/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:45:16 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/24 18:04:51 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_three(t_mem *mem)
{
	ft_findall(mem);
	if (mem->minposition == 0)
	{
		if (mem->maxposition == 1)
		{
			ft_sab(mem, 'a', 0);
			ft_rab(mem, 'a', 0);
		}
	}
	else if (mem->minposition == 1)
	{
		if (mem->maxposition == 2)
			ft_sab(mem, 'a', 0);
		else if (mem->maxposition == 0)
			ft_rab(mem, 'a', 0);
	}
	else if (mem->minposition == 2)
	{
		if (mem->maxposition == 0)
			ft_sab(mem, 'a', 0);
		ft_rrab(mem, 'a', 0);
	}
}

void	ft_five1(t_mem *mem)
{
	if (mem->ras > mem->rras)
	{
		while (ft_findincomb(mem, mem->a[0]) != 0)
			ft_rrab(mem, 'a', 0);
		ft_pab(mem, 'b');
		while (ft_findincomb(mem, mem->a[0]) != 0)
			ft_rab(mem, 'a', 0);
		ft_pab(mem, 'b');
	}
	else
	{
		while (ft_findincomb(mem, mem->a[0]) != 0)
			ft_rab(mem, 'a', 0);
		ft_pab(mem, 'b');
		while (ft_findincomb(mem, mem->a[0]) != 0)
			ft_rrab(mem, 'a', 0);
		ft_pab(mem, 'b');
	}
}

void	ft_fiverra(t_mem *mem, int x)
{
	while (x < (mem->firstasize - (mem->lissize + 1)) && mem->lena > 3)
	{
		if (ft_findincomb(mem, mem->a[0]) == 0)
		{
			ft_pab(mem, 'b');
			x++;
		}
		else
			ft_rrab(mem, 'a', 0);
	}
}

void	ft_fivera(t_mem *mem, int x)
{
	while (x < (mem->firstasize - (mem->lissize + 1)) && mem->lena > 3)
	{
		if (ft_findincomb(mem, mem->a[0]) == 0)
		{
			ft_pab(mem, 'b');
			x++;
		}
		else
			ft_rab(mem, 'a', 0);
	}
}

void	ft_five(t_mem *mem)
{
	int	x;

	x = 0;
	ft_lis(mem);
	if (mem->lissize == 4)
		return ;
	ft_firstliss(mem);
	if (mem->ras == 1 && mem->rras == 1)
		ft_five1(mem);
	else if (mem->ras == 0 && mem->rras == 0)
	{
		ft_pab(mem, 'b');
		ft_rrab(mem, 'a', 0);
		ft_pab(mem, 'b');
	}
	else if (mem->ras > mem->rras)
		ft_fiverra(mem, x);
	else if (mem->ras <= mem->rras)
		ft_fivera(mem, x);
	ft_findall(mem);
	if (mem->lena == 3)
		ft_three(mem);
	ft_freetable(mem->comb, (mem->lissize + 1));
}
