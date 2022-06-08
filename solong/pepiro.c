/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pepiro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:07:42 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:07:45 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_free_matrix(char **matrix, int y)
{
	int	x;

	x = -1;
	while (++x < y)
	{
		if (matrix[x])
			free(matrix[x]);
	}
	free(matrix);
}

void	ft_quit(t_var *box)
{
	ft_printf(box->debug, "Quit Called.");
	if (box->mlx_ptr)
	{
		mlx_destroy_window(box->mlx_ptr, box->win_ptr);
		free(box->mlx_ptr);
	}
	if (box->map_matrix)
		ft_free_matrix(box->map_matrix, box->matrix_y);
	if (box->map_string)
		free(box->map_string);
	if (box->collectible_array)
		free(box->collectible_array);
	if (box->counters)
		free(box->counters);
	if (box->exits_array)
		free(box->exits_array);
	exit(EXIT_SUCCESS);
}

void	ft_putimage(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	main(int pippo, char **topo)
{
	int		x;
	t_var	box;

	x = 0;
	if (pippo != 2)
	{
		ft_printf(1, "Error: Launch syntax: ./pepiro path_to_map\n");
		ft_quit(&box);
	}
	if (!ft_init(&box, topo))
	{
		ft_printf(box.debug, "game started\n");
		ft_printmap(&box);
		ft_parsemap(&box);
		mlx_loop(box.mlx_ptr);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
