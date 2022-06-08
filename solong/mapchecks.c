/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:09:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 19:09:04 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pepiro.h"

// In this function box->counters will be calculated aswell
int	ft_linecheck(t_var *box, char *line, int mode)
{
	int	x;

	x = -1;
	ft_printf(box->debug, "line to check: [%s]\n", line);
	while (line[++x])
	{
		if (mode == 0 && line[x] != '1')
			return (EXIT_FAILURE);
		else
		{
			if ((x == 0 || x == (box->matrix_x - 1)) && line[x] != '1')
				return (EXIT_FAILURE);
			else
			{
				if (!ft_strchr("01CEPX", line[x]))
					return (EXIT_FAILURE);
				ft_obj_count(box, line, x);
			}
		}
	}
	return (EXIT_SUCCESS);
}

// This function will call line checks and check if enough objects of each 
// type has been created

int	ft_compare_matrix_line_size(t_var *box)
{
	int	x;

	x = box->matrix_y;
	while (--x > 0)
		if (ft_strlen(box->map_matrix[x]) != ft_strlen(box->map_matrix[x - 1]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_mapchecks(t_var *box, int y)
{
	int	linechecks;

	linechecks = 0;
	y = -1;
	while (box->map_matrix[++y])
	{
		if (y == 0 || y == (box->matrix_y - 1))
			linechecks += (int)ft_linecheck(box, box->map_matrix[y], 0);
		else
			linechecks += (int)ft_linecheck(box, box->map_matrix[y], 1);
	}
	y = -1;
	while (++y < 3)
		if (box->counters[y] == 0)
			return (EXIT_FAILURE);
	if (linechecks)
		return (EXIT_FAILURE);
	if (box->matrix_x == box->matrix_y)
		return (EXIT_FAILURE);
	if (ft_compare_matrix_line_size(box))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
