/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:07:53 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:07:56 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_addc(t_var *box, int x, int y, int c)
{
	box->collectible_array[c].x = x;
	box->collectible_array[c].y = y;
	box->collectible_array[c].exist = 1;
	box->collectible_array[c].frame = 0;
}

void	ft_adde(t_var *box, int x, int y, int e)
{
	box->exits_array[e].x = x;
	box->exits_array[e].y = y;
	box->exits_array[e].exist = 1;
	box->exits_array[e].frame = 0;
}
