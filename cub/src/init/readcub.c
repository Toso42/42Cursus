/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:03:17 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 17:33:09 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	_check_directions(t_mlx *game_env, char **split)
{
	if (!ft_strcmp_precision(split[0], "NO"))
		game_env->map->ntexture = (void *)ft_strtrimfree(ft_strdup(split[1]),
				"\n");
	if (!ft_strcmp_precision(split[0], "SO"))
		game_env->map->stexture = (void *)ft_strtrimfree(ft_strdup(split[1]),
				"\n");
	if (!ft_strcmp_precision(split[0], "WE"))
		game_env->map->wtexture = (void *)ft_strtrimfree(ft_strdup(split[1]),
				"\n");
	if (!ft_strcmp_precision(split[0], "EA"))
		game_env->map->etexture = (void *)ft_strtrimfree(ft_strdup(split[1]),
				"\n");
}

/**
 * @brief resolves regular lines.
 * 
 * @param readen_cubline 
 * @param game_env 
 * @return int 
 */
static int	_split_count_fill(char *readen_cubline, t_mlx *game_env)
{
	char	**split;
	int		error;

	error = 0;
	if (!ft_strcmp_precision(readen_cubline, "\n"))
		return (0);
	split = ft_split(readen_cubline, ' ');
	if (ft_sarsize(split) != 2)
		error = print_error("wrong arguments for colors line");
	_check_directions(game_env, split);
	ft_sarfree(split, ft_sarsize(split));
	_rgb_check(game_env, readen_cubline);
	if (error)
		return (EXIT_FAILURE);
	return (0);
}

/**
 * @brief reads map.cub line per line.
 * 
 * @param game_env 
 * @param readen_cub 
 * @return int 
 */
static int	_fill_mapstruct(t_mlx *game_env, char **readen_cub)
{
	int	y;

	y = -1;
	while (readen_cub[++y])
	{
		if (_if_is_a_map_line(readen_cub[y]) == TRUE)
			return (fill_map(game_env, readen_cub, y));
		if (_split_count_fill(readen_cub[y], game_env))
			return (EXIT_FAILURE);
	}
	return (0);
}

/**
 * @brief mallocates, read map.cub, parse map and assign values in 
 * game->map structure.
 * 
 * @param argv_arg 
 * @param game_env 
 * @return t_mlx* 
 */
int	read_cubfile_create_mapstruct(char *argv_arg, t_mlx *game_env)
{
	int		map_fd;
	char	**readen_cub;
	char	*next_line;

	readen_cub = NULL;
	next_line = NULL;
	map_fd = open(argv_arg, O_RDONLY);
	if (map_fd < 0)
		return (print_error("couldn't open the file"));
	next_line = get_next_line(map_fd);
	if (next_line)
		readen_cub = ft_saradd_back(readen_cub, next_line);
	while (next_line)
	{
		free(next_line);
		next_line = get_next_line(map_fd);
		readen_cub = ft_saradd_back(readen_cub, next_line);
	}
	if (_fill_mapstruct(game_env, readen_cub))
		print_error("error filling struct");
	if (readen_cub)
		ft_sarfree(readen_cub, ft_sarsize(readen_cub));
	free(next_line);
	close(map_fd);
	return (EXIT_SUCCESS);
}
