/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:07:44 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/03/27 17:24:37 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	ft_findincomb(t_mem *mem, int x)
{
	int	i;

	i = -1;
	while (++i <= mem->lissize)
	{
		if (mem->comb[mem->lissize][i] == x)
			return (1);
	}
	return (0);
}

int	ft_atoi(t_mem *mem, char *str)
{
	long	x;
	long	y;

	y = 0;
	x = 1;
	while (*str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			x *= -1;
		str++;
	}
	while (*str <= 57 && *str >= 48)
	{
		y = (y * 10) + ((*str - 48) % 10);
		str++;
	}
	y = y * x;
	if (y > 2147483647 || y < -2147483648)
		ft_error(mem);
	return ((int)y);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cp;

	if (n == 0)
		return ;
	i = -1;
	cp = s;
	while (++i < n)
		cp[i] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	len = count * size;
	ptr = (size_t *) malloc (len);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}

void	ft_answer(t_mem *mem, char *rule, int rulelen)
{
	int		x;
	int		y;
	char	*newanswer;
	int		newlen;

	newlen = (mem->answerlen + rulelen + 1);
	x = 0;
	y = 0;
	newanswer = (char *)malloc(newlen * sizeof(char));
	if (mem->answerlen > 0)
	{
		while (mem->answer[x] != '\0')
		{
			newanswer[x] = mem->answer[x];
			x++;
		}
	}
	while (rule[y] != '\0')
		newanswer[x++] = rule[y++];
	newanswer[x] = '\0';
	free(mem->answer);
	mem->answer = newanswer;
	mem->answerlen = (newlen - 1);
}
