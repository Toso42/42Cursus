/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:52:06 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/22 14:22:27 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	free_game(t_mlx *game)
{
	if (game->player.plap)
		free(game->player.plap);
	if (game->d.h)
		free(game->d.h);
	if (game->map->ntexture)
		ft_free(game->map->ntexture);
	if (game->map->stexture)
		ft_free(game->map->stexture);
	if (game->map->wtexture)
		ft_free(game->map->wtexture);
	if (game->map->etexture)
		ft_free(game->map->etexture);
	if (game->map->floor)
		free(game->map->floor);
	if (game->map->ceiling)
		free(game->map->ceiling);
	if (game->movd.h)
		free(game->movd.h);
	if (game->map->maparray)
		ft_sarfree(game->map->maparray, ft_sarsize(game->map->maparray));
	if (game->map)
		free(game->map);
	if (game->window_instance)
		mlx_destroy_window(game->mlx_instance, game->window_instance);
	if (game->mlx_instance)
		ft_free(game->mlx_instance);
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
