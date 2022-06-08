/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:47:47 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:25:30 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_changepatrols2(t_var *box, int which, int how, clock_t now)
{
	if (how == 1)
	{
		if ((now - box->patrols[which].last) >= 50000)
		{
			ft_printmatrixcell(box, box->patrols[which].y,
				box->patrols[which].x);
			ft_printf(box->debug, "x: %d", (box->patrols[which].x
					+= ((int)pow(-1, (1 << 31 & (box->player.x
									- box->patrols[which].x)) >> 31))
					- (rand() & 1)));
			ft_printf(box->debug, "y: %d\n", (box->patrols[which].y
					+= ((int)pow(-1, (1 << 31 & (box->player.y
									- box->patrols[which].y)) >> 31))
					- (rand() & 1)));
			box->patrols[which].last = now;
		}
	}
}

void	ft_changepatrols(t_var *box, int which, int how)
{
	clock_t	now;
	int		frame;
	int		x;

	x = -1;
	now = clock();
	if ((now - box->patrolinterval) > 25000)
	{
		while (++x < box->counters[4])
		{
			frame = box->patrols[x].frame;
			if (frame == 1)
				box->patrols[x].frame = 0;
			else if (frame == 0)
				box->patrols[x].frame = 1;
			ft_changepatrols2(box, which, how, now);
		}
		box->patrolinterval = now;
	}
}

void	ft_render1(t_var *box)
{
	if (box->itoa_moves)
		free(box->itoa_moves);
	ft_printf(1, "moves: %d\n", box->player.moves);
	ft_print_exits(box);
	ft_putpep(box);
	if (box->winning == 2 && (box->current_t - box->won) > 250000)
		ft_win(box);
	if (box->loosing == 2 && (box->current_t - box->lost) > 250000)
		ft_lost(box);
	if (box->counters[3] <= 0 && box->winning == 0)
		ft_exit_condition(box);
	box->start_t = box->current_t;
	if (box->player.movingx != 0 || box->player.movingy != 0)
	{
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
			box->floor.mlx_img, (box->tilesize * (box->player.x
					+ box->player.movingx)), (box->tilesize * (box->player.y
					+ box->player.movingy)));
		box->player.movingx = 0;
		box->player.movingy = 0;
	}
}

void	ft_render2(t_var *box, float finaly, float finalx)
{
	ft_print_collectibles(box);
	if (box->counters[4])
		ft_print_patrols(box);
	if (box->winning == 2 && box->loosing != 2)
	{
		finalx = ((((box->matrix_x - 2) * box->tilesize) / 2));
		finaly = ((((box->matrix_y - 2) * box->tilesize) / 2));
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->fgm.mlx_img,
			finalx, finaly);
	}
	else if (box->loosing == 2 && box->winning != 2)
	{
		ft_printf(1, "loosing == 2\n");
		finalx = ((((box->matrix_x - 2) * box->tilesize) / 2));
		finaly = ((((box->matrix_y - 2) * box->tilesize) / 2));
		ft_printf(1, "finalx = %d finaly %d\n", finalx, finaly);
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->fbm.mlx_img,
			finalx, finaly);
	}
}

int	ft_render(t_var *box)
{
	int		x;
	int		y;
	float	finalx;
	float	finaly;

	x = -1;
	y = -1;
	box->current_t = clock();
	if ((box->current_t - box->start_t) >= 1000)
	{
		if (box->counters[4])
			ft_changepatrols(box, ft_random(0, (box->counters[4] - 1), 5), 1);
		ft_print_moves(box);
		ft_render1(box);
		ft_render2(box, finaly, finalx);
	}
	return (EXIT_SUCCESS);
}
