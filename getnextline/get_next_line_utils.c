/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:14:33 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/02/01 21:36:45 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	creatememutils(char **str1, char *str2, char *swap, size_t b)
{
	size_t	a;
	size_t	xlen;

	a = -1;
	xlen = len(str2);
	while (++a < xlen)
	{
		swap[b] = str2[a];
		b++;
	}
	swap[b] = '\0';
	free(*str1);
	*str1 = swap;
}

void	nextlineutils(char **memory, char *line, size_t *a, size_t *b)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (!((*memory)[x] == '\0' || (*memory)[x] == '\n'))
	{
		line[x] = (*memory)[x];
		x++;
	}
	if ((*memory)[x] == '\n')
	{
		line[x] = '\n';
		line[++x] = '\0';
	}
	else
	{
		line[x] = '\0';
		x++;
	}
	if ((*memory)[x - 1] == '\0')
		x--;
	(*a) = x;
	(*b) = y;
}

void	nextlinechecks(char *rest, char **memory)
{
	free(*memory);
	if (len(rest) > 0)
		(*memory) = rest;
	else
	{
		*memory = NULL;
		free(rest);
	}
}

int	gnlsplitter1(int x, char *buffer, char **memory, int fd)
{
	while (x > 0)
	{
		if (x < 0)
			return (0);
		buffer[x] = '\0';
		(*memory) = createmem(&(*memory), buffer);
		if (checkmem(buffer) == 1)
			break ;
		x = read(fd, buffer, BUFFER_SIZE);
	}
	return (1);
}

int	gnlsplitter2(char *line, char *buffer)
{
	free(buffer);
	if (len(line) == 0)
	{
		free(line);
		line = NULL;
		return (0);
	}
	return (1);
}
