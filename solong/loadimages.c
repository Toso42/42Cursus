/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:13:08 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:13:11 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

// Function to load all needed images into the Box struct.
int	ft_loadimages(t_var *box)
{
	box->wall.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./tiles/wall0.xpm", &box->wall.width, &box->wall.height);
	box->floor.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./tiles/floor2.xpm", &box->floor.width, &box->floor.height);
	box->exit.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./tiles/exit1.xpm", &box->exit.width, &box->exit.height);
	box->per.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/per.xpm", &box->per.width, &box->per.height);
	box->pep0.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/pep0.xpm", &box->pep0.width, &box->pep0.height);
	box->pep1.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/pep1.xpm", &box->pep1.width, &box->pep1.height);
	box->pat0.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/pat0.xpm", &box->pat0.width, &box->pat0.height);
	box->pat1.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/pat1.xpm", &box->pat1.width, &box->pat1.height);
	box->fgm.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/fgm.xpm", &box->fgm.width, &box->fgm.height);
	box->fbm.mlx_img = mlx_xpm_file_to_image(box->mlx_ptr,
			"./sprites/fbm.xpm", &box->fbm.width, &box->fbm.height);
	return (EXIT_SUCCESS);
}
