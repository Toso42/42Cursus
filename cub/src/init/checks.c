/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:30 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/28 13:10:26 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	_player_position(t_mlx *game_env, int x, int y)
{
	if (game_env->map->maparray[y][x] == 'N')
	{
		game_env->player.initial_direction = NORTH;
		game_env->player.pos.x = x + 0.05;
		game_env->player.pos.y = y + 0.05;
	}
	if (game_env->map->maparray[y][x] == 'S')
	{
		game_env->player.initial_direction = SOUTH;
		game_env->player.pos.x = x + 0.05;
		game_env->player.pos.y = y + 0.05;
	}
	if (game_env->map->maparray[y][x] == 'E')
	{
		game_env->player.initial_direction = EAST;
		game_env->player.pos.x = x + 0.05;
		game_env->player.pos.y = y + 0.05;
	}
	if (game_env->map->maparray[y][x] == 'W')
	{
		game_env->player.initial_direction = WEST;
		game_env->player.pos.x = x + 0.05;
		game_env->player.pos.y = y + 0.05;
	}
}

/**
 * @brief still empty. should parse and validate values
 * filled in game_env->map structure.
 * 
 * @param game_env 
 * @return int 
 */
int	_check_map(t_mlx *game_env, int y)
{
	int	x;
	int	player_counter;

	x = -1;
	player_counter = 0;
	while (game_env->map->maparray[++y])
	{
		if (!_if_is_a_map_line(game_env->map->maparray[y]))
			return (print_error("empty line on map"));
		x = -1;
		while (game_env->map->maparray[y][++x])
		{
			if (_is_player_marker(game_env->map->maparray[y][x]))
			{
				_player_position(game_env, x, y);
				player_counter++;
			}
		}
	}
	if (check_enclosure(game_env->map))
		return (print_error("Invalid Map"));
	if (player_counter > 1 || player_counter <= 0)
		return (print_error("invalid spawning point"));
	return (EXIT_SUCCESS);
}

int	_if_is_a_map_line(char *line)
{
	int	x;

	x = -1;
	if (line && line[0] == '\n')
		return (FALSE);
	while (line[++x])
	{
		if (line[x] != ' '
			&& line[x] != '0'
			&& line[x] != '1'
			&& line[x] != 'N'
			&& line[x] != 'S'
			&& line[x] != 'W'
			&& line[x] != 'E'
			&& line[x] != '\n')
			return (FALSE);
	}
	return (TRUE);
}

int	_is_player_marker(char c)
{
	if (c == 'N'
		|| c == 'S'
		|| c == 'W'
		|| c == 'E')
		return (TRUE);
	return (FALSE);
}
