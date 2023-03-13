/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:12 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 11:05:31 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	_pknegative(int *buffer, t_point *start, t_bresenhams *b)
{
	if (b->decide == 0)
	{
		buffer[(int)start->y * W_WIDTH + (int)start->x] = b->color;
		b->pk = b->pk + 2 * b->dy;
	}
	else
	{
		buffer[(int)start->x * W_WIDTH + (int)start->y] = b->color;
		b->pk = b->pk + 2 * b->dy;
	}
}

void	_pkpositive(int *buffer, t_point *start, t_point *end, t_bresenhams *b)
{
	if (start->y < end->y)
		start->y += 1;
	else
		start->y -= 1;
	if (b->decide == 0)
	{
		buffer[(int)start->y * W_WIDTH + (int)start->x] = b->color;
	}
	else
	{
		buffer[(int)start->x * W_WIDTH + (int)start->y] = b->color;
	}
	b->pk = b->pk + 2 * b->dy - 2 * b->dx;
}

void	plotpixel(int *buffer, t_point *start, t_point *end, t_bresenhams *b)
{
	int	i;

	i = -1;
	if (end->x >= W_WIDTH || end->y >= W_HEIGHT)
		return ;
	b->pk = 2 * b->dy - b->dx;
	while (++i <= b->dx)
	{
		if (start->x < end->x)
			start->x += 1;
		else
			start->x -= 1;
		if (b->pk < 0)
			_pknegative(buffer, start, b);
		else
			_pkpositive(buffer, start, end, b);
	}
}

void	bresenhams(t_mlx *game, t_point start, t_point end, int color)
{
	game->b.dx = fabs(end.x - start.x);
	game->b.dy = fabs(end.y - start.y);
	game->b.color = color;
	if (game->b.dx > game->b.dy)
	{
		game->b.decide = 0;
		plotpixel(game->img.data, &start, &end, &game->b);
	}
	else
	{
		game->b.decide = 1;
		game->b.swap = game->b.dx;
		game->b.dx = game->b.dy;
		game->b.dy = game->b.swap;
		game->b.swap = start.x;
		start.x = start.y;
		start.y = game->b.swap;
		game->b.swap = end.x;
		end.x = end.y;
		end.y = game->b.swap;
		plotpixel(game->img.data, &start, &end, &game->b);
	}
}
