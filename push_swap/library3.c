/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:32:34 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 16:54:57 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *string)
{
	int	x;

	x = 0;
	while (string[x])
		x++;
	return (x);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		start = ft_strlen(s);
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	i = 0;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (len--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

static int	nb_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (j == 0))
		{
			j = 1;
			i++;
		}
		if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	**wds_assign(char *s, char c, char **dest, size_t len)
{
	size_t	i;
	size_t	x;
	int		j;

	i = 0;
	x = 0;
	j = -1;
	while (i <= len)
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == len) && j >= 0)
		{
			dest[x++] = ft_substr(s, j, (i - j));
			j = -1;
		}
		i++;
	}
	dest[x] = 0;
	return (dest);
}

char	**ft_split(t_mem *mem, char *s, char c)
{
	char	**dest;
	size_t	len;

	if (!s)
		return (NULL);
	len = (ft_strlen(s));
	dest = (char **) malloc ((nb_words(s, c) + 1) * sizeof(char *));
	mem->argsnumbers = (nb_words(s, c));
	if (!dest)
		return (NULL);
	wds_assign(s, c, dest, len);
	return (dest);
}
