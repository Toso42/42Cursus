/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:52:41 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/22 15:21:29 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	_shift(t_rgb *c)
{
	int	color;

	color = c->r;
	color <<= 8;
	color += c->g;
	color <<= 8;
	color += c->b;
	return (color);
}

void	_colors(t_mlx *game)
{
	game->floorcolor = _shift(game->map->floor);
	free(game->map->floor);
	game->map->floor = NULL;
	game->skycolor = _shift(game->map->ceiling);
	free(game->map->ceiling);
	game->map->ceiling = NULL;
}

int	init_sky_colors(t_mlx *game)
{
	game->walln.img = mlx_xpm_file_to_image(game->mlx_instance,
			game->map->ntexture, &game->walln.img_w, &game->walln.img_h);
	game->walln.data = (int *)mlx_get_data_addr(game->walln.img,
			&game->walln.bpp, &game->walln.line_size, &game->walln.endian);
	game->walls.img = mlx_xpm_file_to_image(game->mlx_instance,
			game->map->stexture, &game->walls.img_w, &game->walls.img_h);
	game->walls.data = (int *)mlx_get_data_addr(game->walls.img,
			&game->walls.bpp, &game->walls.line_size, &game->walls.endian);
	game->wallw.img = mlx_xpm_file_to_image(game->mlx_instance,
			game->map->wtexture, &game->wallw.img_w, &game->wallw.img_h);
	game->wallw.data = (int *)mlx_get_data_addr(game->wallw.img,
			&game->wallw.bpp, &game->wallw.line_size, &game->wallw.endian);
	game->walle.img = mlx_xpm_file_to_image(game->mlx_instance,
			game->map->etexture, &game->walle.img_w, &game->walle.img_h);
	game->walle.data = (int *)mlx_get_data_addr(game->walle.img,
			&game->walle.bpp, &game->walle.line_size, &game->walle.endian);
	_colors(game);
	return (EXIT_SUCCESS);
}
