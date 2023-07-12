/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:27 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/22 15:14:27 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_mlx	*init_game(t_mlx *game)
{
	game = (t_mlx *)malloc(sizeof(t_mlx));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->mlx_instance = mlx_init();
	if (!game
		|| !game->map
		|| !game->mlx_instance)
		return (NULL);
	game->d.h = NULL;
	game->movd.h = NULL;
	game->map->ceiling = NULL;
	game->map->floor = NULL;
	game->map->ntexture = NULL;
	game->map->stexture = NULL;
	game->map->wtexture = NULL;
	game->map->etexture = NULL;
	game->map->maparray = NULL;
	game->window_instance = NULL;
	game->player.plap = NULL;
	game->map->wall_step = 1 / TEXT_SIZE;
	game->minimap.minimap_w = 0;
	game->minimap.minimap_h = 0;
	game->minimap.color = 0;
	game->minimap.tilesize = 0;
	game->lastep = clock();
	return (game);
}

int	init_minimap(t_mlx *game)
{
	game->minimap.minimap_w = 300;
	game->minimap.minimap_h = 300;
	if (game->map->height > game->map->width)
	{
		game->minimap.tilesize = 300 / game->map->height;
		game->minimap.minimap_w = game->minimap.tilesize * game->map->width;
	}
	else
	{
		game->minimap.tilesize = 300 / game->map->width;
		game->minimap.minimap_h
			= game->minimap.tilesize * game->map->height + 10;
	}
	game->minimap.color = 0;
	ft_printf("4 Map initializated\n");
	return (0);
}
