/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:52:06 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/23 15:26:18 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
//frees up texture addresses readen from map.cub
int	free_textures(t_mlx *game)
{
	ft_free(game->map->ntexture);
	game->map->ntexture = NULL;
	ft_free(game->map->stexture);
	game->map->stexture = NULL;
	ft_free(game->map->wtexture);
	game->map->wtexture = NULL;
	ft_free(game->map->etexture);
	game->map->etexture = NULL;
	return (0);
}

int	free_game(t_mlx *game)
{
	if (game->player.plap)
		free(game->player.plap);
	if (game->d.h)
		free(game->d.h);
	free_textures(game);
	if (game->map->floor)
		free(game->map->floor);
	if (game->map->ceiling)
		free(game->map->ceiling);
	if (game->movd.h)
		free(game->movd.h);
	if (game->map->maparray)
		ft_sarfree(game->map->maparray, game->map->height);
	if (game->map)
		free(game->map);
	if (game->window_instance)
		mlx_destroy_window(game->mlx_instance, game->window_instance);
	if (game)
		free(game);
	return (1);
}

int	end_program(t_mlx *game)
{
	free_game(game);
	game = NULL;
	exit(0);
}
