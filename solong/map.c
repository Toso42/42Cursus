/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:12:12 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:12:15 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

// Hashing function to put tyles to mlx_window before loop starts.

void	ft_hashmap(t_var *box, char what, int x, int y)
{
	if (what == '0' || what == 'C' || what == 'P' || what == 'X')
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
			box->floor.mlx_img, (box->tilesize * x),
			(box->tilesize * y));
	if (what == '1' || what == 'E')
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr,
			box->wall.mlx_img, (box->tilesize * x),
			(box->tilesize * y));
}

// This function is called Once before loop to put background images (tyles)
// to mlx_window pointer, through a hashing function. It will scan through 
// Map_Matrix and pass the elements to hashing function.

void	ft_printmap(t_var *box)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (box->map_matrix[++y])
	{
		while (box->map_matrix[y][++x])
			ft_hashmap(box, box->map_matrix[y][x], x, y);
		x = -1;
	}
	ft_printf(box->debug, "map printed\n");
}

// This function will print the Map_Matrix

void	ft_printmatrix(t_var *box, int x)
{
	box->matrix_y = x;
	x = -1;
	ft_printf(box->debug, "--Map Matrix:\n");
	while (++x < box->matrix_y)
		ft_printf(box->debug, "%s\n", box->map_matrix[x]);
	box->matrix_x = ft_strlen(box->map_matrix[0]);
	ft_printf(box->debug, "--End Matrix\nMatrix Height: %d\nMatrix Width: %d\n",
		box->matrix_y, box->matrix_x);
}

// This function will create a char* Map_Matrix sourcing from the input map.
// At the end, if Debug mode activated, it will print it on the stdout.
int	ft_createmap(t_var *box)
{
	int		x;
	char	*mapline;
	char	*nextline;

	mapline = (char *)malloc(sizeof(char *));
	mapline[0] = 0;
	x = 0;
	box->map_fd = open(box->map_path, O_RDONLY);
	if (box->map_fd < 0)
		return (EXIT_FAILURE);
	nextline = get_next_line(box->map_fd);
	while (nextline)
	{
		x++;
		mapline = ft_strjoin(1, (const char *)mapline, (const char *)nextline);
		nextline = get_next_line(box->map_fd);
	}
	ft_printf(0, "mapline: [%s]\n", mapline);
	box->map_matrix = ft_split(1, mapline, '\n');
	ft_printmatrix(box, x);
	return (EXIT_SUCCESS);
}
