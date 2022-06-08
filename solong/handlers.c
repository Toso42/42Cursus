/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:16:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:16:04 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

//Each Function in this file is a Handler
int	ft_handle_closewin(t_var *box)
{
	ft_printf(box->debug, "Close Window Button:\n");
	ft_quit(box);
	return (EXIT_SUCCESS);
}

void	ft_moveplayer2(t_var *box, int key)
{
	if (key == KEY_A && box->map_matrix[box->player.y][box->player.x - 1]
		!= '1')
	{
		box->player.x -= 1;
		box->player.movingx = 1;
	}
	else if (key == KEY_D && box->map_matrix[box->player.y][box->player.x + 1]
		!= '1')
	{
		box->player.x += 1;
		box->player.movingx = -1;
	}
	box->player.moves += 1;
}

void	ft_moveplayer(t_var *box, int key)
{
	if (box->player.exist && (clock() - box->player.last) > 5000)
	{
		box->player.last = clock();
		if (key == KEY_W && box->map_matrix[box->player.y - 1][box->player.x]
			!= '1')
		{
			box->player.y -= 1;
			box->player.movingy = 1;
		}
		else if (key == KEY_S && box->map_matrix[box->player.y + 1]
			[box->player.x] != '1')
		{
			box->player.y += 1;
			box->player.movingy = -1;
		}
		else
			ft_moveplayer2(box, key);
	}
}

int	ft_handle_keypress(int key, t_var *box)
{
	if (key == KEY_ESC)
	{
		ft_printf(box->debug, "quit\n");
		ft_quit(box);
	}
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		ft_moveplayer(box, key);
	return (EXIT_SUCCESS);
}
