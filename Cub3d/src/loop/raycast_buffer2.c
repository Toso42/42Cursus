/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_buffer2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:50:31 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 22:54:07 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	raycast_to_buffer_draw(t_mlx *game)
{
	_background(game);
	_raycast(game);
	_render_scene(game);
}
