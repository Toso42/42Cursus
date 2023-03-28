/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:14:23 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/28 13:10:12 by tdi-leo          ###   ########.fr       */
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
	if (((y == 0 || y == map->height - 1) || (x == 0 || x == map->width - 1))
		&& (map->maparray[y][x] == '0' || _is_player_marker(map->maparray[y][x]) == TRUE))
		return (print_error("0 or Player on border"));
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
			if (map->maparray[y][x] == '0' || _is_player_marker(map->maparray[y][x]) == TRUE)
			{
				if (_check_borders(map, x, y))
					return (EXIT_FAILURE);
				if ((x > 0 && y > 0)
					&& (_is_not_surrounded(map, x, y) == TRUE))
						return (print_error("player or floor not surrounded"));
			}
		}
	}
	return (EXIT_SUCCESS);
}

//checks map file extension
int	check_extension(char *arg, char *extension)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = ft_strlen(extension);
	if (!arg[i] || j == 0)
		return (1);
	while (arg[i])
		i++;
	if (i < j)
		return (1);
	p = &arg[i - j];
	if (ft_strcmp(p, extension))
		return (1);
	return (0);
}

int	check_texturefiles(t_mlx *game)
{
	int	fd;

	fd = 0;
	fd = open((char *)game->map->ntexture, O_RDONLY);
	if (fd == -1)
		return (ft_printf("can't open texture files\n"));
	fd = open((char *)game->map->stexture, O_RDONLY);
	if (fd == -1)
		return (ft_printf("can't open texture files\n"));
	fd = open((char *)game->map->wtexture, O_RDONLY);
	if (fd == -1)
		return (ft_printf("can't open texture files\n"));
	fd = open((char *)game->map->etexture, O_RDONLY);
	if (fd == -1)
		return (ft_printf("can't open texture files\n"));
	if (check_extension(game->map->ntexture, ".xpm")
		|| check_extension(game->map->stexture, ".xpm")
		|| check_extension(game->map->wtexture, ".xpm")
		|| check_extension(game->map->etexture, ".xpm"))
		return (1);
	ft_printf("texture files checked\n");
	return (0);
}
