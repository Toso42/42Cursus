/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:33:46 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 15:39:46 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

static int	_yfloor_is_out(t_mlx *game, t_point *step)
{
	if ((step->y - floor(step->y) < 0.03)
		|| (game->map->maparray[(int)floor(step->y)][(int)step->x] == '1'
		&& floor(step->y) - step->y < 0.03))
		return (1);
	return (0);
}

static int	_yceil_is_out(t_mlx *game, t_point *step)
{
	if (ceil(step->y) - step->y > 0.03
		|| (game->map->maparray[(int)ceil(step->y)][(int)step->x] == '1'
		&& ceil(step->y) - step->y < 0.03))
		return (1);
	return (0);
}

static int	_xfloor_is_out(t_mlx *game, t_point *step)
{
	if ((step->x - floor(step->x) < 0.03)
		|| (game->map->maparray[(int)step->y][(int)floor(step->x)] == '1'
		&& floor(step->x) - step->x < 0.03))
		return (1);
	return (0);
}

static int	_xceil_is_out(t_mlx *game, t_point *step)
{
	if (ceil(step->x) - step->x > 0.03
		|| (game->map->maparray[(int)step->y][(int)ceil(step->x)] == '1'
		&& ceil(step->x) - step->x < 0.03))
		return (1);
	return (0);
}

void	_limit_boundary2(t_mlx *game, t_point *pre, t_point *step)
{
	if (pre->y - step->y <= 0)
	{
		if (_yfloor_is_out(game, step))
			step->y = floor(step->y) + 0.03;
	}
	else if (pre->y - step->y >= 0)
	{
		if (_yceil_is_out(game, step))
				step->y = ceil(step->y) - 0.03;
	}
	else if (pre->x - step->x <= 0)
	{
		if (_xfloor_is_out(game, step))
			step->x = floor(step->x) + 0.03;
	}
	else if (pre->x - step->x >= 0)
	{
		if (_xceil_is_out(game, step))
				step->x = ceil(step->x) - 0.03;
	}
}
