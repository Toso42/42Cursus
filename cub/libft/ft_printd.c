/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:47:07 by tdi-leo           #+#    #+#             */
/*   Updated: 2023/03/13 12:04:57 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(va_list args, const char *string, int sum, int x)
{
	if (string[x] == 'c')
		sum += ft_putchar(va_arg(args, int));
	else if (string[x] == 's')
		ft_printftypestring(args, NULL, sum);
	else if (string[x] == 'd' || string[x] == 'i')
		sum = ft_putnmb(va_arg(args, int), sum);
	else if (string[x] == 'u')
		sum = ft_putnmbu(va_arg(args, unsigned int), sum);
	else if (string[x] == '%')
		sum += ft_putchar('%');
	else if (string[x] == 'x')
		sum = ft_putnmbx(va_arg(args, unsigned int), sum, "0123456789abcdef");
	else if (string[x] == 'X')
		sum = ft_putnmbcx(va_arg(args, unsigned int), sum, "0123456789ABCDEF");
	else if (string[x] == 'p')
		sum = ft_pad(va_arg(args, unsigned long long), sum, "0123456789abcdef");
	else if (string[x] == 'b')
		sum += ft_printbits(8, va_arg(args, int));
	else if (string[x] == 'B')
		sum += ft_printbits(16, va_arg(args, int));
	else if (string[x] == 'i')
		sum += ft_printbits(32, va_arg(args, int));
	return (sum);
}

int	ft_printd(int flag, const char *string, ...)
{
	int		sum;
	va_list	args;
	int		x;

	va_start(args, string);
	x = -1;
	sum = 0;
	if (flag)
	{
		while (string[++x] != 0)
		{
			if (string[x] == '%')
				sum = ft_type(args, string, sum, ++x);
			else
				sum += ft_putchar(string[x]);
		}
	}
	va_end(args);
	return (sum);
}
