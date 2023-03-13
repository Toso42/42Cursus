/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:48:05 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/10 19:02:50 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	get_end_point(t_point start, t_point dir, double distance)
{
	t_point	end;
	double	dir_lenght;
	double	dx;
	double	dy;

	dir_lenght = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	dx = dir.x / dir_lenght;
	dy = dir.y / dir_lenght;
	end.x = start.x + dx * distance;
	end.y = start.y + dy * distance;
	return (end);
}

t_point	dilate_vector(t_point a, double scalar)
{
	a.x *= scalar;
	a.y *= scalar;
	return (a);
}

t_point	get_plane_dir(t_mlx *game, t_point dir)
{
	t_point	pla_dir;

	dir = game->player.dir;
	normalize_point(&dir);
	pla_dir.x = dir.x * cos(M_PI / 2) - dir.y * sin(M_PI / 2);
	pla_dir.y = dir.x * sin(M_PI / 2) + dir.y * cos(M_PI / 2);
	pla_dir = dilate_vector(pla_dir, tan(M_PI * 2 * (66.0 / 2.0) / 360));
	return (pla_dir);
}

t_point	vectorial_sum(const t_point *a, const t_point *b)
{
	t_point	answer;

	answer.x = a->x + b->x;
	answer.y = a->y + b->y;
	return (answer);
}

t_point	calculate_point_on_line(t_point point, t_point direction,
	double increment, int casedir)
{
	t_point	result;
	double	slope;

	if (casedir == 1)
	{
		slope = (direction.y - point.y) / (direction.x - point.x);
		result.y = slope * (increment - point.x) + point.y;
		result.x = increment;
	}
	else
	{
		slope = (direction.x - point.x) / (direction.y - point.y);
		result.x = slope * (increment - point.y) + point.x;
		result.y = increment;
	}
	print_point(result, "result");
	return (result);
}
