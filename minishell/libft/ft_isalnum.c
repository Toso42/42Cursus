/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:42:53 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/01/21 12:42:54 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c < 48 || c > 122 || (c < 'a' && c > 'Z') || (c < 65 && c > 57))
		return (0);
	return (1);
}