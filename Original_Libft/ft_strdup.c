/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:46:38 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/01/21 12:46:40 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenght;
	char	*dest;

	lenght = ft_strlen(s1);
	dest = (char *) malloc ((lenght + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memmove(dest, s1, lenght);
	dest[lenght] = '\0';
	return (dest);
}
