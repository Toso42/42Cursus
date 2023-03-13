/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:04 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 17:33:47 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	_draw_img(t_mlx *game)
{
	mlx_put_image_to_window(game->mlx_instance, game->window_instance,
		game->img.img, 0, 0);
	mlx_do_sync(game->mlx_instance);
}

int	game_loop(t_mlx *game)
{
	check_events(game);
	calibrate_miniplayer(game);
	raycast_to_buffer_draw(game);
	minimap_to_buffer_draw(game);
	_draw_img(game);
	return (0);
}
