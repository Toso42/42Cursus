/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:45:16 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/01/21 12:45:17 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cp1;
	const unsigned char	*cp2;

	i = -1;
	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (cp1[i] != cp2[i])
			return ((unsigned int)(cp1[i] - cp2[i]));
	}
	return (0);
}
