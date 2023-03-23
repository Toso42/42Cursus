/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:14:23 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/23 12:46:12 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	_is_not_surrounded(t_map *map, int x, int y)
{
	if (map->maparray[y - 1][x] == ' '
		|| map->maparray[y - 1][x] == '	'
		|| map->maparray[y + 1][x] == ' '
		|| map->maparray[y + 1][x] == '	'
		|| map->maparray[y][x - 1] == ' '
		|| map->maparray[y][x - 1] == '	'
		|| map->maparray[y][x + 1] == ' '
		|| map->maparray[y][x + 1] == '	')
		return (TRUE);
	return (FALSE);
}

static int	_check_borders(t_map *map, int x, int y)
{
	if (y == 0
		|| y == map->height - 1)
		return (EXIT_FAILURE);
	if (x == 0
		|| x == map->width - 1)
		return (EXIT_FAILURE);
	if ((y == 0 || x == 0) && map->maparray[y][x] == '0')
		return (print_error("0 on border"));
	return (EXIT_SUCCESS);
}

int	check_enclosure(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->maparray[++y])
	{
		x = -1;
		while (map->maparray[y][++x])
		{
			if (map->maparray[y][x] == '0')
			{
				if (_check_borders(map, x, y))
					return (EXIT_FAILURE);
				if ((x > 0 && y > 0) && (map->maparray[y][x] == '0')
					&& _is_not_surrounded(map, x, y) == TRUE)
					return (print_error("0 not surrounded"));
			}
		}
	}
	return (EXIT_SUCCESS);
}

//todo check cub name.

//todo check invalid texture path.

//todo too big rgb.

//todo leak su empty lines mappa

//todo collision muri spigolo convesso