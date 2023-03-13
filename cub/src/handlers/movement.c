/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:49 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 16:15:37 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handlers.h"

t_point	limit_boundary(t_mlx *game, t_point *step)
{
	t_point	pre;

	pre = (*step);
	if (game->map->maparray[(int)step->y][(int)game->player.pos.x] == '1')
		step->y = game->player.pos.y;
	if (game->map->maparray[(int)game->player.pos.y][(int)step->x] == '1')
		step->x = game->player.pos.x;
	printf("pre %f %f\n", step->x, step->y);
	_limit_boundary2(game, &pre, step);
	printf("post %f %f\n", step->x, step->y);
	return ((*step));
}

void	move_up(t_mlx *game)
{
	t_point	movement;

	movement = get_end_point(game->player.pos, game->player.dir,
			game->player.mov_step);
	movement = limit_boundary(game, &movement);
	game->player.pos.y = movement.y;
	game->player.pos.x = movement.x;
}

void	move_behind(t_mlx *game)
{
	t_point	movement;

	movement = get_end_point(game->player.pos, game->player.dir,
			-game->player.mov_step);
	movement = limit_boundary(game, &movement);
	game->player.pos.y = movement.y;
	game->player.pos.x = movement.x;
}

void	rotate_right(t_mlx *game)
{
	double	old_dir_x;
	double	rot_step;

	rot_step = game->player.rot_step;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot_step)
		- game->player.dir.y * sin(rot_step);
	game->player.dir.y = old_dir_x * sin(rot_step)
		+ game->player.dir.y * cos(rot_step);
	old_dir_x = game->player.pla_dir.x;
	game->player.pla_dir.x = game->player.pla_dir.x * cos(rot_step)
		- game->player.pla_dir.y * sin(rot_step);
	game->player.pla_dir.y = old_dir_x * sin(rot_step)
		+ game->player.pla_dir.y * cos(rot_step);
}

void	rotate_left(t_mlx *game)
{
	double	old_dir_x;
	double	rot_step;

	rot_step = game->player.rot_step;
	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(-rot_step)
		- game->player.dir.y * sin(-rot_step);
	game->player.dir.y = old_dir_x * sin(-rot_step)
		+ game->player.dir.y * cos(-rot_step);
	old_dir_x = game->player.pla_dir.x;
	game->player.pla_dir.x = game->player.pla_dir.x * cos(-rot_step)
		- game->player.pla_dir.y * sin(-rot_step);
	game->player.pla_dir.y = old_dir_x * sin(-rot_step)
		+ game->player.pla_dir.y * cos(-rot_step);
}
