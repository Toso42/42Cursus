/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:51:56 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/10 19:04:05 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../../main.h"

typedef struct s_mlx	t_mlx;
typedef struct s_point	t_point;

//time
void	ms_wait(int amount);
//print
void	print_point(t_point point, char *name);
int		print_error(char *error);
//math
t_point	round_point(t_point p);
double	distance(t_point p1, t_point p2);
double	magnitude(t_point *v);
void	normalize_point(t_point *in);
t_point	inverse_point(t_point in);
//point_math
t_point	get_end_point(t_point start, t_point dir, double distance);
t_point	dilate_vector(t_point a, double scalar);
t_point	get_plane_dir(t_mlx *game, t_point dir);
t_point	vectorial_sum(const t_point *a, const t_point *b);
t_point	calculate_point_on_line(t_point point, t_point direction,
			double increment, int casedir);
//else
int		which_color(char c);
int		error(char *str);
int		free_game(t_mlx *game);
int		end_program(t_mlx *game);
void	print_env(t_mlx *game_env);

#endif
