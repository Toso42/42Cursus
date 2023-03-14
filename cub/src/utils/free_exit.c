/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:52:06 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 20:11:01 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	free_game(t_mlx *game)
{
	if (game->map->maparray)
		ft_sarfree(game->map->maparray, ft_sarsize(game->map->maparray));
	if (game->map)
		free(game->map);
	if (game->d.h)
		free(game->d.h);
	if (game->window_instance)
		mlx_destroy_window(game->mlx_instance, game->window_instance);
	free(game->movd.h);
	game->map = NULL;
	free(game);
	return (1);
}

int	end_program(t_mlx *game)
{
	free_game(game);
	game = NULL;
	exit(0);
}
