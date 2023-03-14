/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:46 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 17:30:29 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

int	key_press(int key, t_mlx *game)
{
	if (key == K_ESC)
		game->key.key_esc = 1;
	if (key == K_AR_U || key == KEY_W)
		game->key.key_up = 1;
	if (key == K_AR_R)
		game->key.key_right = 1;
	if (key == K_AR_L)
		game->key.key_left = 1;
	if (key == K_AR_D || key == KEY_S)
		game->key.key_down = 1;
	if (key == KEY_A)
		game->key.key_sidel = 1;
	if (key == KEY_D)
		game->key.key_sider = 1;
	return (0);
}

int	key_release(int key, t_mlx *game)
{
	if (key == K_ESC)
		game->key.key_esc = 0;
	else if (key == K_AR_U || key == KEY_W)
		game->key.key_up = 0;
	else if (key == K_AR_R)
		game->key.key_right = 0;
	else if (key == K_AR_L)
		game->key.key_left = 0;
	else if (key == K_AR_D || key == KEY_S)
		game->key.key_down = 0;
	else if (key == KEY_A)
		game->key.key_sidel = 0;
	else if (key == KEY_D)
		game->key.key_sider = 0;
	return (0);
}

void	check_events(t_mlx *game)
{
	if (game->key.key_up)
		move_up(game);
	if (game->key.key_down)
		move_behind(game);
	if (game->key.key_right)
		rotate_right(game);
	if (game->key.key_left)
		rotate_left(game);
	if (game->key.key_sidel)
		move_left(game);
	if (game->key.key_sider)
		move_right(game);
	if (game->key.key_esc)
	{
		ft_printf("Esc pressed\n");
		free_game(game);
		game = NULL;
		exit(0);
	}
}
