/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:07 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 11:22:27 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	calc_step_sidedist(t_point *point, t_point *vector, t_dda *d)
{
	if (vector->x < 0)
	{
		d->stepx = -1;
		d->sidedistx = (point->x - floor(point->x)) * d->deltadistx;
	}
	else
	{
		d->stepx = 1;
		d->sidedistx = (floor(point->x) + 1.0 - point->x) * d->deltadistx;
	}
	if (vector->y < 0)
	{
		d->stepy = -1;
		d->sidedisty = (point->y - floor(point->y)) * d->deltadisty;
	}
	else
	{
		d->stepy = 1;
		d->sidedisty = (floor(point->y) + 1.0 - point->y) * d->deltadisty;
	}
}

void	init_deltas(t_point *vector, t_dda *d)
{
	if (vector->x == 0)
		d->deltadistx = 1e30;
	else
		d->deltadistx = fabs(1.0 / vector->x);
	if (vector->y == 0)
		d->deltadisty = 1e30;
	else
		d->deltadisty = fabs(1.0 / vector->y);
}

void	adjust_hitpoint(t_point *p, t_point *v, t_dda *d)
{
	if (0 == d->side)
	{
		if (d->sidedistx < d->deltadistx)
			d->euclide = d->sidedistx;
		else
			d->euclide = d->sidedistx - d->deltadistx;
	}
	else
	{
		if (d->sidedisty < d->deltadisty)
			d->euclide = d->sidedisty;
		else
			d->euclide = d->sidedisty - d->deltadisty;
	}
	d->result = dilate_vector((*v), d->euclide);
	d->result = vectorial_sum(p, &d->result);
}

void	_wall_other_side(t_mlx *game, t_point *point, t_point *ray, t_dda *d)
{
	if (ray->y - point->y >= 0)
	{
		d->h[(int)d->w_cursor].color = WALLN;
		d->h[(int)d->w_cursor].texture.x = (d->h[(int)d->w_cursor].hit.x
				- floor(d->h[(int)d->w_cursor].hit.x)) * WALL_SIZE;
		d->h[(int)d->w_cursor].timg = &game->walle;
	}
	else
	{
		d->h[(int)d->w_cursor].color = WALLS;
		d->h[(int)d->w_cursor].texture.x = (d->h[(int)d->w_cursor].hit.x
				- floor(d->h[(int)d->w_cursor].hit.x)) * WALL_SIZE;
		d->h[(int)d->w_cursor].timg = &game->wallw;
	}
}

/**
 * @brief checks from which side the wall is hit and assign textures
 * accordingly
 * 
 * @param game 
 * @param point 
 * @param ray 
 * @param d 
 */
void	wall_side(t_mlx *game, t_point *point, t_point *ray, t_dda *d)
{
	if (d->h[(int)d->w_cursor].side == 0)
	{
		if (ray->x - point->x >= 0)
		{
			d->h[(int)d->w_cursor].color = WALLW;
			d->h[(int)d->w_cursor].texture.x = (d->h[(int)d->w_cursor].hit.y
					- floor(d->h[(int)d->w_cursor].hit.y)) * WALL_SIZE;
			d->h[(int)d->w_cursor].timg = &game->walln;
		}
		else
		{
			d->h[(int)d->w_cursor].color = WALLE;
			d->h[(int)d->w_cursor].texture.x = (d->h[(int)d->w_cursor].hit.y
					- floor(d->h[(int)d->w_cursor].hit.y)) * WALL_SIZE;
			d->h[(int)d->w_cursor].timg = &game->walls;
		}
	}
	else
		_wall_other_side(game, point, ray, d);
}
