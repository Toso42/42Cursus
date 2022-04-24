/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:10:43 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/02/01 21:35:26 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	len(char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*createmem(char **str1, char *str2)
{
	size_t	a;
	size_t	b;
	size_t	tlen;
	char	*swap;
	size_t	xlen;

	a = -1;
	b = 0;
	tlen = (len(*str1) + len(str2));
	swap = (char *)malloc(tlen + 1);
	if (!swap)
		return (NULL);
	if (*str1 != NULL)
	{
		xlen = len(*str1);
		while (++a < xlen)
		{
			swap[b] = (*str1)[a];
			b++;
		}
		swap[b] = '\0';
	}
	creatememutils(&(*str1), str2, swap, b);
	return (*str1);
}

int	checkmem(char *str3)
{
	int	x;

	x = 0;
	while (!(str3[x] == '\0' || str3[x] == '\n'))
	{
		x++;
	}
	if (str3[x] == '\n')
	{
		return (1);
	}
	return (0);
}

char	*next_line(char **memory)
{
	char	*line;
	char	*rest;
	size_t	x;
	size_t	y;
	size_t	z;

	if (!*memory)
		return (NULL);
	y = 0;
	x = 0;
	while (!((*memory)[y] == '\n' || (*memory)[y] == '\0'))
		y++;
	line = (char *)malloc(y + 2);
	if (!line)
		return (NULL);
	nextlineutils(&(*memory), line, &x, &y);
	z = len(*memory);
	z -= y;
	rest = (char *)malloc(z + 1);
	y = 0;
	while ((*memory)[x] != '\0')
		rest[y++] = (*memory)[x++];
		rest[y] = '\0';
	nextlinechecks(rest, &(*memory));
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*memory;
	char			*line;
	int				x;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	x = read(fd, buffer, BUFFER_SIZE);
	if (x < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (gnlsplitter1(x, buffer, &memory, fd) == 0)
		return (NULL);
	line = next_line(&memory);
	if (gnlsplitter2(line, buffer) == 0)
		return (NULL);
	return (line);
}
/*
int	main(void)
{
	int	fd;

	fd = open("text3.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
*/
