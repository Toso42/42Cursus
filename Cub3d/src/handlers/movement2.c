/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:49 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/11 10:32:34 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

void	move_right(t_mlx *game)
{
	t_point	movement;

	movement = get_end_point(game->player.pos, game->player.pla_dir,
			game->player.side_step);
	movement = limit_boundary(game, &movement);
	game->player.pos.y = movement.y;
	game->player.pos.x = movement.x;
}

void	move_left(t_mlx *game)
{
	t_point	movement;

	movement = get_end_point(game->player.pos, game->player.pla_dir,
			-game->player.side_step);
	movement = limit_boundary(game, &movement);
	game->player.pos.y = movement.y;
	game->player.pos.x = movement.x;
}
