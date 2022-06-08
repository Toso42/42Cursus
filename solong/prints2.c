/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:01:12 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:01:17 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_printmatrixcell(t_var *box, int y, int x)
{
	if (ft_strchr("0CX", box->map_matrix[y][x]))
		ft_printfloor(box, y, x);
	else if (box->map_matrix[y][x] == 'E')
		ft_printexit(box, y, x);
	else
		ft_printwall(box, y, x);
}

void	ft_printwall(t_var *box, int y, int x)
{
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->wall.mlx_img,
		(box->tilesize * x), (box->tilesize * y));
}

void	ft_printfloor(t_var *box, int y, int x)
{
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->floor.mlx_img,
		(box->tilesize * x), (box->tilesize * y));
}

void	ft_printexit(t_var *box, int y, int x)
{
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->exit.mlx_img,
		(box->tilesize * x), (box->tilesize * y));
}

void	ft_putpep(t_var *box)
{
	clock_t	now;

	now = clock();
	if ((now - box->player.last) > 25000)
	{
		if (box->player.frame == 0)
			box->player.frame = 1;
		else if (box->player.frame == 1)
			box->player.frame = 0;
		box->player.last = now;
	}
	if (box->player.frame == 0)
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->pep0.mlx_img,
			(box->tilesize * box->player.x), (box->tilesize * box->player.y));
	else if (box->player.frame == 1)
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, box->pep1.mlx_img,
			(box->tilesize * box->player.x), (box->tilesize * box->player.y));
}
