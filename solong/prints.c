/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:04:10 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:04:12 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_print_moves(t_var *box)
{
	char	*moves;

	box->itoa_moves = ft_itoa(box->player.moves);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
		box->wall.mlx_img, 0, 0);
	mlx_string_put(box->mlx_ptr, box->win_ptr, 15, 15, WHITE, box->itoa_moves);
}

void	ft_print_exits(t_var *box)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < box->counters[2])
	{
		x = box->exits_array[i].x;
		y = box->exits_array[i].y;
		if (box->exits_array[i].exist)
			mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
				box->exit.mlx_img, (box->tilesize * x), (box->tilesize * y));
	}
}

void	ft_print_collectibles(t_var *box)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < box->counters[0])
	{
		x = box->collectible_array[i].x;
		y = box->collectible_array[i].y;
		if (box->collectible_array[i].exist)
		{
			if (box->player.x != x || box->player.y != y)
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
					box->per.mlx_img, (box->tilesize * x), (box->tilesize * y));
			else
			{
				box->collectible_array[i].exist = 0;
				box->counters[3] -= 1;
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
					box->floor.mlx_img, (box->tilesize * x),
					(box->tilesize * y));
			}
		}
	}
}

void	ft_print_patrols(t_var *box)
{
	int	lcounters[3];

	lcounters[0] = -1;
	while (++lcounters[0] < box->counters[4])
	{
		lcounters[1] = box->patrols[lcounters[0]].x;
		lcounters[2] = box->patrols[lcounters[0]].y;
		if (box->patrols[lcounters[0]].exist)
		{
			ft_printmatrixcell(box, lcounters[2], lcounters[1]);
			if (box->patrols[lcounters[0]].frame == 0)
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
					box->pat0.mlx_img, (box->tilesize * lcounters[1]),
					(box->tilesize * lcounters[2]));
			else if (box->patrols[lcounters[0]].frame == 1)
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
					box->pat1.mlx_img, (box->tilesize * lcounters[1]),
					(box->tilesize * lcounters[2]));
		}
		if (box->player.x == lcounters[1] && box->player.y == lcounters[2])
		{
			box->loosing = 2;
			box->lost = clock();
		}
	}
}
