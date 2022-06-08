/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:14:15 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:22:07 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

// Function to init hooks.
int	ft_inithooks(t_var *box)
{
	mlx_loop_hook(box->mlx_ptr, ft_render, box);
	mlx_hook(box->win_ptr, 2, (1L << 0), ft_handle_keypress, box);
	mlx_hook(box->win_ptr, 17, (1L << 17), ft_handle_closewin, box);
	return (0);
}

// Function to init box.
int	ft_init_box(t_var *box, char **topo)
{
	box->debug = 0;
	box->mlx_ptr = NULL;
	box->win_ptr = NULL;
	box->itoa_moves = NULL;
	box->map_path = topo[1];
	box->map_string = NULL;
	box->map_matrix = NULL;
	box->matrix_y = 0;
	box->matrix_x = 0;
	box->tilesize = 64;
	box->winning = 0;
	box->loosing = 0;
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
	{
		ft_printf(box->debug, "mlx error");
		ft_quit(box);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Function to init box.
int	ft_init_box2(t_var *box)
{
	box->collectible_array = NULL;
	box->exits_array = NULL;
	box->counters = (int *)malloc(5 * (sizeof(int)));
	if (!box->counters)
		return (EXIT_FAILURE);
	box->counters[0] = 0;
	box->counters[1] = 0;
	box->counters[2] = 0;
	box->counters[3] = 0;
	box->counters[4] = 0;
	return (EXIT_SUCCESS);
}

// Function to init the second part of the box, making use of the Map_Matrix
// created before being called.
int	ft_init_box3(t_var *box)
{
	box->win_ptr = mlx_new_window(box->mlx_ptr, (box->tilesize * box->matrix_x),
			(box->tilesize * box->matrix_y), "Pepiro: SDT");
	if (!box->win_ptr)
	{
		ft_printf(box->debug, "win error");
		ft_quit(box);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// Function to call and create Box struct, Map, Map_Matrix, and Objects
int	ft_init(t_var *box, char **topo)
{
	if (ft_init_box(box, topo) || ft_init_box2(box))
		return (EXIT_FAILURE);
	if (ft_createmap(box) || ft_mapchecks(box, 0))
	{
		ft_printf(1, "ERROR: Invalid Map Layout\n");
		return (EXIT_FAILURE);
	}
	if (ft_init_box3(box))
		return (EXIT_FAILURE);
	ft_inithooks(box);
	ft_loadimages(box);
	ft_createobjects(box);
	return (EXIT_SUCCESS);
}
