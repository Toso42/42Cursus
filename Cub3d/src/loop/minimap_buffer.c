/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:02:23 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 11:05:12 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	_player(t_mlx *game)
{
	t_point	mm_square;
	t_point	mm_reset;

	mm_square = game->miniplayer.pos;
	mm_square.x -= 2;
	mm_reset = mm_square;
	mm_square.y -= 2;
	while (mm_square.y <= mm_reset.y + 2)
	{
		mm_square.x = mm_reset.x;
		while (mm_square.x <= mm_reset.x + 4)
		{
			game->img.data[(int)mm_square.y * W_WIDTH + (int)mm_square.x]
				= WHITE;
			mm_square.x += 1;
		}
		mm_square.y += 1;
	}
}

void	_minitile(t_mlx *game, int mat_y, int mat_x, int color)
{
	int	mini_x;
	int	mini_y;
	int	mini_x_next;
	int	mini_y_next;
	int	mini_x_reset;

	color = which_color(game->map->maparray[mat_y][mat_x]);
	mini_x = mat_x * game->minimap.tilesize ;
	mini_y = mat_y * game->minimap.tilesize ;
	mini_x_next = mini_x + game->minimap.tilesize;
	mini_y_next = mini_y + game->minimap.tilesize;
	mini_x_reset = mini_x;
	while (mini_y <= mini_y_next)
	{
		mini_x = mini_x_reset;
		while (mini_x <= mini_x_next)
		{
			game->img.data[mini_y * W_WIDTH + mini_x] = color;
			mini_x++;
		}
		mini_y++;
	}
}

void	_tyles(t_mlx *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
			_minitile(game, y, x, 0);
	}
}

void	_canvas(t_mlx *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->minimap.minimap_h)
	{
		x = -1;
		while (++x < game->minimap.minimap_w)
			game->img.data[y * W_WIDTH + x] = BLACK;
	}
	y = -1;
}

void	minimap_to_buffer_draw(t_mlx *game)
{
	_canvas(game);
	_tyles(game);
	_player(game);
	_fov(game);
}
