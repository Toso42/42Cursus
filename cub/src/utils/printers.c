/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:35 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 22:47:12 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_env(t_mlx *game_env)
{
	ft_printf("-----\nn: %s\ns: %s\n",
		game_env->map->ntexture, game_env->map->stexture);
	ft_printf("w: %s\ne: %s\n", game_env->map->wtexture,
		game_env->map->etexture);
	ft_printf("player direction: %d\n", game_env->player.initial_direction);
	ft_printf("map_w: %d, map_h: %d\n", game_env->map->width,
		game_env->map->height);
	ft_printf("map height: %d\n", ft_sarsize(game_env->map->maparray));
	ft_printf("mini_tilesize: %d\n", game_env->minimap.tilesize);
	printf("player x: %f y: %f\n", game_env->player.pos.x,
		game_env->player.pos.y);
	ft_sarprint(game_env->map->maparray);
}

void	print_point(t_point point, char *name)
{
	printf("{ %s x: %f y: %f }\n", name, point.x, point.y);
}

int	print_error(char *error)
{
	ft_printf("%s\n", error);
	return (1);
}
