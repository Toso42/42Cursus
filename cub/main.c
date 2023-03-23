/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:57:14 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/23 15:06:15 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	_mlx_init(t_mlx *game)
{
	game->window_instance = mlx_new_window(game->mlx_instance, W_WIDTH,
			W_HEIGHT, "Cub3d");
	game->img.img = mlx_new_image(game->mlx_instance, W_WIDTH, W_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_size, &game->img.endian);
	mlx_loop_hook(game->mlx_instance, &game_loop, game);
	mlx_hook(game->window_instance, KEY_EXIT, (1L << 17), &end_program, game);
	mlx_hook(game->window_instance, KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->window_instance, KEY_RELEASE, 0, &key_release, game);
	return (0);
}

/**
 * @brief Main function allocates structures, then read from map argument,
 * create a map array, checks that everything is in order, initialize
 * player and minimap structures accordingly, then initialize mlx istance
 * and window. Game loop then is launched.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_mlx	*game;

	game = NULL;
	if (argc != 2)
		return (print_error("Only ./Cub3d + valid map"));
	if (check_extension(argv[1], ".cub"))
		return (print_error("Wrong mapfile format"));
	game = init_game(game);
	if (!game
		|| read_cubfile_create_mapstruct(argv[1], game)
		|| (!game->map->ceiling || !game->map->floor)
		|| check_texturefiles(game)
		|| _check_map(game, -1)
		|| init_minimap(game)
		|| init_player(game)
		|| _mlx_init(game)
		|| init_sky_colors(game))
		return (free_game(game));
	print_env(game);
	mlx_loop(game->mlx_instance);
	free_game(game);
	return (EXIT_SUCCESS);
}
