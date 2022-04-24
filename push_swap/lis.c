/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:55:24 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 16:56:33 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_newcomb(t_mem *mem, int **ar, int nb, int pos)
{
	pos = 0;
	ar[0] = (int *)malloc(sizeof(int));
	ft_checkmalloc(mem, *ar);
	ar[0][0] = nb;
}

void	ft_newrow(t_mem *mem, int **ar, int nb, int pos)
{
	int	i;

	i = -1;
	ar[pos] = (int *) malloc(sizeof(int) * (pos + 1));
	ft_checkmalloc(mem, *ar);
	while (++i != pos)
		ar[pos][i] = ar[pos - 1][i];
	ar[pos][i] = nb;
}

void	ft_checkmiddle(int **ar, int nb, int pos)
{
	int	i;

	i = -1;
	while (nb < ar[pos][pos])
		pos--;
	while (++i < pos + 1)
		ar[pos + 1][i] = ar[pos][i];
	ar[pos + 1][pos + 1] = nb;
}

void	ft_lis(t_mem *mem)
{
	int	row;
	int	i;

	mem->comb = (int **) malloc (sizeof(int *) * mem->lena);
	ft_checkmalloc(mem, mem->comb);
	i = mem->minposition;
	ft_newcomb(mem, mem->comb, mem->a[i], 0);
	row = 0;
	i += 1;
	if (i == mem->lena)
		i = 0;
	while (i != mem->minposition)
	{
		if (mem->a[i] > mem->comb[row][row])
			ft_newrow(mem, mem->comb, mem->a[i], ++row);
		else
			ft_checkmiddle(mem->comb, mem->a[i], row);
		i++;
		if (i == mem->lena)
			i = 0;
	}
	mem->lissize = row;
}
