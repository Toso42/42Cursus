/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calibration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:13:34 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/10 19:46:16 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	calibrate_miniplayer(t_mlx *game)
{
	double	tilesize;

	tilesize = game->minimap.tilesize;
	game->miniplayer.pos.x = game->player.pos.x * tilesize;
	game->miniplayer.pos.y = game->player.pos.y * tilesize;
	game->miniplayer.dir.x = game->player.dir.x * tilesize;
	game->miniplayer.dir.y = game->player.dir.y * tilesize;
	game->miniplayer.pla_dir.x = game->player.pla_dir.x * tilesize;
	game->miniplayer.pla_dir.y = game->player.pla_dir.y * tilesize;
	game->miniplayer.pla_dist = game->player.pla_dist * tilesize;
	game->miniplayer.pos_reset = game->miniplayer.pos;
}
