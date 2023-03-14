/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_buffer2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:07:57 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 11:01:59 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	_fov(t_mlx *game)
{
	int	cursor;

	cursor = 0;
	while (cursor < W_WIDTH)
	{
		bresenhams(game, game->miniplayer.pos,
			dilate_vector(game->d.h[cursor].hit, game->minimap.tilesize),
			RED);
		cursor++;
	}
}
