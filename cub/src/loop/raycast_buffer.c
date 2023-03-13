/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:43:44 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 12:05:49 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	_raycast(t_mlx *game)
{
	game->d.w_cursor = 0;
	while (game->d.w_cursor < W_WIDTH)
	{
		game->d.fraction = 2 * (game->d.w_cursor / (W_WIDTH - 1.0f)) - 1;
		game->d.h[(int)game->d.w_cursor].pladir_dil
			= dilate_vector(game->player.pla_dir, game->d.fraction);
		game->d.h[(int)game->d.w_cursor].true_ray
			= vectorial_sum(&game->d.h[(int)game->d.w_cursor].pladir_dil,
				&game->player.dir);
		game->d.h[(int)game->d.w_cursor].normal_ray
			= game->d.h[(int)game->d.w_cursor].true_ray;
		normalize_point(&game->d.h[(int)game->d.w_cursor].normal_ray);
		dda(game, &game->player.pos,
			&game->d.h[(int)game->d.w_cursor].normal_ray, &game->d);
		game->d.w_cursor += 1.0;
	}
}

int	wall_pixel(t_hitpoint *p, int k, int wh)
{
	p->texture.y = roundf((double)k * (double)WALL_SIZE / (double)wh);
	return (p->timg->data[(int)p->texture.y * (p->timg->line_size / 4)
			+ (int)p->texture.x]);
}

void	_draw_line(t_mlx *game, int vline, int hlinestart, int hlineend)
{
	int	windowend;

	game->d.wallcursor = 0;
	game->d.wallheight = hlineend - hlinestart + 1;
	if (hlinestart < 0)
		game->d.wallcursor = hlinestart * -1;
	windowend = game->d.wallcursor + W_HEIGHT;
	while (game->d.wallcursor < game->d.wallheight - 1
		&& game->d.wallcursor <= windowend)
	{
		if ((hlinestart + game->d.wallcursor) >= 0
			&& (hlinestart + game->d.wallcursor) <= W_HEIGHT)
			game->img.data[(hlinestart + game->d.wallcursor)
				* (game->img.line_size / 4) + vline]
				= wall_pixel(&game->d.h[vline], game->d.wallcursor,
					game->d.wallheight);
		game->d.wallcursor += 1;
	}
}

void	_render_scene(t_mlx *game)
{
	int	cursor;
	int	wallstart;
	int	wallend;
	int	wallheight;

	cursor = 0;
	while (cursor < W_WIDTH)
	{
		wallheight = ceil(W_HEIGHT / game->d.h[cursor].perp_dist);
		wallstart = ceil(-wallheight / 2 + W_HEIGHT / 2);
		if (wallstart < INT16_MIN)
			wallstart = INT16_MIN;
		wallend = wallheight / 2 + W_HEIGHT / 2;
		if (wallend >= INT16_MAX)
			wallend = INT16_MAX;
		_draw_line(game, cursor, wallstart, wallend);
		cursor++;
	}
}

void	_background(t_mlx *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			if (y < W_HEIGHT / 2)
			{
				game->img.data[y * W_WIDTH + x] = game->skycolor;
			}
			else
				game->img.data[y * W_WIDTH + x] = game->floorcolor;
		}
	}
}
