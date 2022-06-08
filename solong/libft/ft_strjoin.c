/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:46:57 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 18:45:37 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Flags: 0 no free 1 frees both strings
char	*ft_strjoin(int flag, char const *s1, char const *s2)
{
	char	*united;
	int		i;
	int		j;

	ft_printf(0, "s1: [%s]\n s2: [%s]", s1, s2);
	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	united = (char *) malloc ((sizeof(char))
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	ft_printf(0, "%s", united);
	if (flag && s1)
		free((char *)s1);
	if (flag && s2)
		free((char *)s2);
	return (united);
}
