/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:08:38 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:08:41 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

void	ft_obj_count(t_var *box, char *line, int x)
{
	if (line[x] == 'C')
	{
		box->counters[0] += 1;
		box->counters[3] += 1;
	}
	else if (line[x] == 'P')
		box->counters[1] += 1;
	else if (line[x] == 'E')
		box->counters[2] += 1;
	else if (line[x] == 'X')
		box->counters[4] += 1;
}

// Function to create Objects (Collectibles, Exits, Player)
void	ft_createobjects(t_var *box)
{
	int	x;

	x = -1;
	box->collectible_array = malloc(sizeof(t_obj) * box->counters[0]);
	box->exits_array = malloc(sizeof(t_obj) * box->counters[2]);
	box->patrols = malloc(sizeof(t_obj) * box->counters[4]);
}

// Function to initialize Player
void	ft_addp(t_var *box, int x, int y)
{
	box->player.x = x;
	box->player.y = y;
	box->player.exist = 1;
	box->player.last = 0;
	box->player.frame = 0;
	box->player.movingx = 0;
	box->player.movingy = 0;
	box->player.moves = 0;
}

// Function to initialize Patrols
void	ft_addx(t_var *box, int x, int y, int p)
{
	box->patrols[p].x = x;
	box->patrols[p].y = y;
	box->patrols[p].exist = 1;
	box->patrols[p].frame = 0;
	box->patrols[p].last = 0;
	box->patrols[p].movingx = 0;
	box->patrols[p].movingy = 0;
}

// Object creation must be delegated to function with statics int if more type
// of Objects have to be implemented.
void	ft_parsemap(t_var *box)
{
	int	counters[5];

	counters[0] = -1;
	counters[1] = -1;
	counters[2] = -1;
	counters[3] = -1;
	counters[4] = -1;
	while (++counters[0] < box->matrix_y)
	{
		while (++counters[1] < box->matrix_x)
		{
			if (box->map_matrix[counters[0]][counters[1]] == 'C')
				ft_addc(box, counters[1], counters[0], ++counters[2]);
			else if (box->map_matrix[counters[0]][counters[1]] == 'E')
				ft_adde(box, counters[1], counters[0], ++counters[3]);
			else if (box->map_matrix[counters[0]][counters[1]] == 'P')
				ft_addp(box, counters[1], counters[0]);
			else if (box->map_matrix[counters[0]][counters[1]] == 'X')
				ft_addx(box, counters[1], counters[0], ++counters[4]);
		}
		counters[1] = -1;
	}
	box->start_t = clock();
}
