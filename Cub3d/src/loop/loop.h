/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:02:51 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 23:02:47 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H
# include "../../main.h"

typedef struct s_mlx		t_mlx;
typedef struct s_point		t_point;
typedef struct s_dda		t_dda;
typedef struct s_map		t_map;
typedef struct s_hitpoint	t_hitpoint;
//bresenhams
void	bresenhams(t_mlx *game, t_point start, t_point end, int color);
//dda
void	perpendicular_distance(t_dda *d);
void	calc_step_sidedist(t_point *point, t_point *vector, t_dda *d);
void	init_deltas(t_point *vector, t_dda *d);
void	adjust_hitpoint(t_point *p, t_point *v, t_dda *d);
void	perpendicular_distance(t_dda *d);
void	wall_side(t_mlx *game, t_point *point, t_point *ray, t_dda *d);
t_point	dda(t_mlx *game, t_point *point, t_point *vector, t_dda *d);
//calibration
void	calibrate_miniplayer(t_mlx *game);
//void	calc_plane_points(t_mlx *game);
void	raycast_to_buffer_draw(t_mlx *game);
void	minimap_to_buffer_draw(t_mlx *game);
int		game_loop(t_mlx *game);
//minimap_buffer
void	_fov(t_mlx *game);
//raycast buffer
void	_raycast(t_mlx *game);
int		wall_pixel(t_hitpoint *p, int k, int wh);
void	_draw_line(t_mlx *game, int vline, int hlinestart, int hlineend);
void	_render_scene(t_mlx *game);
void	_background(t_mlx *game);
void	raycast_to_buffer_draw(t_mlx *game);

#endif
