/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:05:25 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/21 22:05:49 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_finalcheck(t_mem *mem, char what)
{
	int	x;
	int	*arg;
	int	*len;

	len = NULL;
	if (what == 'a')
	{
		arg = mem->a;
		len = &mem->lena;
	}
	else if (what == 'b')
	{
		arg = mem->b;
		len = &mem->lenb;
	}
	x = -1;
	while (++x < (len[0] - 1))
	{
		if (arg[x] > arg[x + 1])
			return (0);
	}
	return (1);
}
