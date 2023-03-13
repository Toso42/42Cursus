/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:29:47 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 23:02:12 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	perpendicular_distance(t_dda *d)
{
	d->h[(int)d->w_cursor].tray_mod
		= magnitude(&d->h[(int)d->w_cursor].true_ray);
	d->h[(int)d->w_cursor].perp_dist
		= (d->euclide - d->h[(int)d->w_cursor].tray_mod)
		/ d->h[(int)d->w_cursor].tray_mod + 1;
}

void	_deltasums(t_mlx *game, t_dda *d)
{
	if (d->sidedistx < d->sidedisty)
	{
		d->sidedistx += d->deltadistx;
		d->result.x += d->stepx;
		d->side = 0;
	}
	else
	{
		d->sidedisty += d->deltadisty;
		d->result.y += d->stepy;
		d->side = 1;
	}
	if (game->map->maparray[(int)d->result.y][(int)d->result.x] == '1')
		d->hit = 1;
}

t_point	dda(t_mlx *game, t_point *point, t_point *vector, t_dda *d)
{
	d->hit = 0;
	d->result.x = floor(point->x);
	d->result.y = floor(point->y);
	init_deltas(vector, d);
	calc_step_sidedist(point, vector, d);
	while (d->hit == 0)
		_deltasums(game, d);
	adjust_hitpoint(point, vector, d);
	perpendicular_distance(d);
	d->h[(int)d->w_cursor].hit = d->result;
	d->h[(int)d->w_cursor].side = d->side;
	wall_side(game, point, &d->result, d);
	return (d->h[(int)d->w_cursor].hit);
}
