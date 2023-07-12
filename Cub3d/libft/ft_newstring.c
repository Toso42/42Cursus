/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:29:41 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/10 19:47:20 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newstring(char c, int len)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * len + 1);
	ft_memset(string, c, len);
	string[len] = 0;
	return (string);
}
