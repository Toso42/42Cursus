/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:00:19 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/10 18:59:28 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point	round_point(t_point p)
{
	t_point	rounded;

	rounded.x = round(p.x);
	rounded.y = round(p.y);
	return (rounded);
}

double	distance(t_point p1, t_point p2)
{
	double	dx;
	double	dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	return (sqrt(dx * dx + dy * dy));
}

double	magnitude(t_point *v)
{
	double	magnitude;

	magnitude = sqrtf((v->x * v->x) + (v->y * v->y));
	return (magnitude);
}

void	normalize_point(t_point *in)
{
	double	modulus;

	modulus = sqrtf(powf(in->x, 2.) + powf(in->y, 2.));
	in->x *= 1.0f / modulus;
	in->y *= 1.0f / modulus;
}

t_point	inverse_point(t_point in)
{
	t_point	out;

	out.x = -in.x;
	out.y = -in.y;
	return (out);
}
