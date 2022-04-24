/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:21:40 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/27 17:16:01 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_prep1(t_mem *mem)
{
	int	i;
	int	newlen;

	newlen = mem->lena;
	i = -1;
	while (++i <= mem->firstasize)
	{
		if ((mem->a[0] <= (mem->firstasize / 3))
			&& ft_findincomb(mem, mem->a[0]) == 0)
			ft_pab(mem, 'b');
		else
			ft_rab(mem, 'a', 0);
	}
	i = -1;
	newlen = mem->lena;
	while (++i <= newlen)
	{
		if ((mem->a[0] <= (mem->firstasize / 3 * 2) && mem->a[0]
				>= (mem->firstasize / 3)) && ft_findincomb(mem, mem->a[0]) == 0)
			ft_pab(mem, 'b');
		else
			ft_rab(mem, 'a', 0);
	}
}

void	ft_prep2(t_mem *mem)
{
	int	i;
	int	newlen;

	i = -1;
	newlen = mem->lena;
	while (++i <= newlen)
	{
		if ((mem->a[0] >= (mem->firstasize / 3 * 2))
			&& ft_findincomb(mem, mem->a[0]) == 0)
			ft_pab(mem, 'b');
		else
			ft_rab(mem, 'a', 0);
	}
	i = -1;
	mem->firstasize = mem->lena;
	ft_findall(mem);
	while (mem->a[0] != mem->min)
		ft_rab(mem, 'a', 0);
}

void	ft_prep3(t_mem *mem)
{
	int	i;

	i = -1;
	if (ft_finalcheck(mem, 'a') == 0 && (mem->lissize + 1) < mem->firstasize)
	{
		while (++i < mem->firstasize)
		{
			if (ft_findincomb(mem, mem->a[0]) == 0)
				ft_pab(mem, 'b');
			else
				ft_rab(mem, 'a', 0);
		}
	}
}

int	ft_prep(t_mem *mem)
{
	if (mem->lissize == 4 && mem->lena == 5)
		return (1);
	if (ft_finalcheck(mem, 'a') == 1 && mem->lenb == 0)
		return (0);
	if ((mem->lena == 3 && mem->firstasize != 5))
	{
		ft_three(mem);
		return (1);
	}
	if (mem->lena + mem->lenb == 5)
		return (1);
	ft_lis(mem);
	if (mem->lissize < (mem->firstasize / 3) && mem->lena > 5)
	{
		ft_prep1(mem);
		ft_prep2(mem);
		ft_freetable(mem->comb, (mem->lissize + 1));
	}
	else
	{
		ft_prep3(mem);
		ft_freetable(mem->comb, (mem->lissize + 1));
		ft_findall(mem);
	}
	return (1);
}
