/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillrbs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:17:56 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/20 15:18:10 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_fillrb(t_mem *mem)
{
	int	i;

	i = -1;
	while (++i < mem->lenb)
		mem->table[i][3] = i;
}

void	ft_fillrrb(t_mem *mem)
{
	int	i;
	int	j;

	j = mem->lenb;
	i = 0;
	while (++i < mem->lenb)
		mem->table[--j][4] = i;
}
