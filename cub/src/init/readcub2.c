/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcub2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:54:09 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/23 17:37:54 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	_assemble_maparray(t_mlx *game_env, t_mapfill *m, char **readen_cub,
	int from)
{
	m->y = from;
	m->x = 0;
	while (readen_cub[m->y])
	{
		game_env->map->maparray[m->x]
			= ft_strtrimfree(ft_strdup(readen_cub[m->y]), "\n");
		m->cur_len = ft_strlen(game_env->map->maparray[m->x]);
		if (m->cur_len < m->max_len)
		{
			m->cur_len = m->max_len - m->cur_len;
			game_env->map->maparray[m->x]
				= ft_strjoinfree(game_env->map->maparray[m->x],
					ft_newstring(' ', m->cur_len));
		}
		m->y += 1;
		m->x += 1;
	}
	ft_printf("map sarsize after trim: %d\n",
		ft_sarsize(game_env->map->maparray));
}

static void	_calc_size(t_mlx *game_env, t_mapfill *m, char **readen_cub,
	int from)
{
	(void)game_env;
	m->x = from;
	m->y = from;
	m->max_len = (int)ft_strlen(readen_cub[from]) - 1;
	while (readen_cub[m->y])
		m->y += 1;
	m->map_height = m->y - from;
	while (readen_cub[m->x])
	{
		m->cur_len = (int)ft_strlen(readen_cub[m->x]) - 1;
		if (m->cur_len > m->max_len)
			m->max_len = m->cur_len;
		m->x += 1;
	}
}

/**
 * @brief resolves map lines. If an empty or wrong line is found
 * an error is printed.
 * 
 * @param game_env 
 * @param readen_cub 
 * @param from 
 * @return int 
 */
int	fill_map(t_mlx *game_env, char	**readen_cub, int from)
{
	t_mapfill	m;

	_calc_size(game_env, &m, readen_cub, from);
	ft_printf("height: %d\n", m.map_height);
	game_env->map->maparray = (char **)malloc(sizeof(char *)
			* m.map_height + 1);
	game_env->map->maparray[m.map_height] = NULL;
	_assemble_maparray(game_env, &m, readen_cub, from);
	game_env->map->height = m.map_height;
	game_env->map->width = m.max_len;
	return (0);
}
