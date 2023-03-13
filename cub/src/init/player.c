/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:21 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 12:05:38 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	_direction(t_mlx *game)
{
	if (game->player.initial_direction == NORTH)
	{
		game->player.dir.x = 0.0;
		game->player.dir.y = -1.0;
	}
	else if (game->player.initial_direction == SOUTH)
	{
		game->player.dir.x = 0.0;
		game->player.dir.y = 1.0;
	}
	else if (game->player.initial_direction == WEST)
	{
		game->player.dir.x = 1.0;
		game->player.dir.y = 0.0;
	}
	else if (game->player.initial_direction == EAST)
	{
		game->player.dir.x = -1.0;
		game->player.dir.y = 0.0;
	}
}

int	init_player(t_mlx *game)
{
	_direction(game);
	game->player.pla_dist = 0.66;
	game->player.pla_dir = get_plane_dir(game, game->player.dir);
	game->player.mov_step = 0.07;
	game->player.rot_step = 0.07;
	game->player.side_step = 0.07;
	game->key.key_down = 0;
	game->key.key_left = 0;
	game->key.key_right = 0;
	game->key.key_up = 0;
	game->key.key_esc = 0;
	game->key.key_sidel = 0;
	game->key.key_sider = 0;
	game->d.h = (t_hitpoint *)malloc(sizeof(t_hitpoint) * W_WIDTH);
	ft_printf("Player initialized:\n");
	print_point(game->player.pos, "pos");
	print_point(game->player.dir, "dir");
	return (EXIT_SUCCESS);
}
