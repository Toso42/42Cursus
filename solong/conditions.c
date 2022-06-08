/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:38:38 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:17:20 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_win(t_var *box)
{
	int	x;
	int	y;

	ft_printf(1, "Win condition met\n");
	ft_quit(box);
}

void	ft_lost(t_var *box)
{
	ft_printf(1, "Loose condition met\n");
	ft_quit(box);
}

int	ft_exit_condition(t_var *box)
{
	int	j;

	j = -1;
	while (++j < box->counters[2])
	{
		ft_printf(0, "Checking if player x,y: %d,%d == exit x,y : %d,%d \n",
			box->player.x, box->player.y, box->exits_array[j].x,
			box->exits_array[j].y);
		if (box->player.x == box->exits_array[j].x && box->player.y
			== box->exits_array[j].y)
		{
			ft_printf(box->debug, "Exit Condition Met\n");
			box->winning = 2;
			box->won = clock();
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_random(int min, int max, int range)
{
	int	random;
	int	x;

	x = -1;
	while (++x < range)
	{
		random = (rand() % (max - min + 1)) + min;
	}
	return (random);
}
