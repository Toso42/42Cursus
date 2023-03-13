/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:24 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 23:07:18 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include "../../main.h"

typedef struct s_mlx		t_mlx;
typedef struct s_point		t_point;
typedef struct s_dda		t_dda;
typedef struct s_map		t_map;
typedef struct s_mapfill	t_mapfill;

//rgb
int		_rgb_check(t_mlx *game, char *rgb);
//read_cub
int		read_cubfile_create_mapstruct(char *argv_arg, t_mlx *game_env);
//read_cub_2
int		fill_map(t_mlx *game_env, char	**readen_cub, int from);
//init
t_mlx	*init_game(t_mlx *game);
int		init_player(t_mlx *game);
int		init_minimap(t_mlx *game);
int		init_sky_colors(t_mlx *game);
// checks
int		check_enclosure(t_map *map);
int		_check_map(t_mlx *game_env, int y);
int		_is_player_marker(char c);
int		_if_is_a_map_line(char *line);

//imgs
int		load_textures(t_mlx *tex);
//calibration
void	calibrate_miniplayer(t_mlx *game);

#endif
