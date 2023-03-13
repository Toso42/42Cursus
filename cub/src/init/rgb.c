/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:54:29 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/12 23:03:57 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static t_rgb	*_fill_rgb(t_rgb *rgb_struct, char **rgbsplit)
{
	ft_sarprint(rgbsplit);
	ft_printf("error here\n");
	ft_printf("%s\n", rgbsplit[0]);
	rgb_struct = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb_struct)
		return (NULL);
	rgb_struct->r = ft_atoi(rgbsplit[0]);
	rgb_struct->g = ft_atoi(rgbsplit[1]);
	rgb_struct->b = ft_atoi(ft_strtrim(rgbsplit[2], "\n"));
	if (rgb_struct->r > 255
		|| rgb_struct->g > 255
		|| rgb_struct->b > 255)
		return (NULL);
	return (rgb_struct);
}

static char	**_rgbsplit(char **rgbsplit, char **split)
{
	rgbsplit = ft_split(split[1], ',');
	if (ft_sarsize(rgbsplit) != 3)
	{
		ft_sarfree(split, ft_sarsize(split));
		ft_sarfree(rgbsplit, ft_sarsize(rgbsplit));
		return (NULL);
	}
	ft_sarprint(rgbsplit);
	return (rgbsplit);
}

static int	_check_situation(char **split, int *which)
{
	if (ft_strcmp_precision(split[0], "F")
		&& ft_strcmp_precision(split[0], "C"))
	{
		ft_sarfree(split, ft_sarsize(split));
		return (1);
	}
	if (!ft_strcmp_precision(split[0], "F"))
		(*which) = 1;
	if (!ft_strcmp_precision(split[0], "C"))
		(*which) = 2;
	return (0);
}

int	_rgb_check(t_mlx *game, char *rgb)
{
	char	**split;
	char	**rgbsplit;
	t_rgb	*rgb_struct;
	int		which;

	which = 0;
	split = ft_split(rgb, ' ');
	rgbsplit = NULL;
	rgb_struct = NULL;
	if (_check_situation(split, &which))
		return (EXIT_SUCCESS);
	rgbsplit = _rgbsplit(rgbsplit, split);
	if (rgbsplit)
		rgb_struct = _fill_rgb(rgb_struct, rgbsplit);
	if (split)
		ft_sarfree(split, ft_sarsize(split));
	if (rgb)
		ft_sarfree(rgbsplit, ft_sarsize(rgbsplit));
	if (which == 1)
		game->map->floor = rgb_struct;
	else
		game->map->ceiling = rgb_struct;
	return (EXIT_SUCCESS);
}