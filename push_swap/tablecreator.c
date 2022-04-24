/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablecreator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:08:39 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 16:57:31 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_createtable(t_mem *mem)
{
	int	i;

	i = -1;
	ft_freetable(mem->table, mem->oldtablesize);
	mem->table = (int **)malloc(sizeof(int *) * mem->lenb);
	ft_checkmalloc(mem, mem->table);
	while (++i < mem->lenb)
	{
		mem->table[i] = ft_calloc(6, sizeof(int));
		ft_checkmalloc(mem, mem->table[i]);
	}
	mem->oldtablesize = mem->lenb;
}

void	ft_tablecreator(t_mem *mem)
{
	ft_createtable(mem);
	ft_fillra(mem);
	ft_fillrra(mem);
	ft_fillrb(mem);
	ft_fillrrb(mem);
	ft_tablecalc(mem);
	ft_findmintable(mem);
	ft_exec(mem);
}
