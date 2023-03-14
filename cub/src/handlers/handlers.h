/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:42 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 17:33:55 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../../main.h"

typedef struct s_mlx	t_mlx;
typedef struct s_point	t_point;
typedef struct s_dda	t_dda;
//key events
int			key_press(int key, t_mlx *game);
int			key_release(int key, t_mlx *game);
void		check_events(t_mlx *game);
//boundary
t_point		limit_boundary(t_mlx *game, t_point *step);
void		_limit_boundary2(t_mlx *game, t_point *pre, t_point *step);
//movement
void		move_up(t_mlx *game);
void		move_behind(t_mlx *game);
void		rotate_right(t_mlx *game);
void		rotate_left(t_mlx *game);
void		move_right(t_mlx *game);
void		move_left(t_mlx *game);

#endif
