/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:47:07 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/02/07 21:16:36 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *astring, int Sum)
{
	int	x;

	x = -1;
//	printf("stringa:%s\n", astring);
	while (astring[++x] != 0)
		Sum += ft_putchar(astring[x]);
	return (Sum);
}

int ft_putnmbu(unsigned int n, int Sum)
{
	if (n >= 10)
	{
		Sum = ft_putnmbu((n / 10), Sum);
		Sum = ft_putnmbu((n % 10), Sum);
	}
	else
		Sum += ft_putchar(48 + n);
	return (Sum);
}

int ft_putnmb(int n, int Sum)
{
	if (n == -2147483648)
	{
		Sum += ft_putchar('-');
		Sum += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		Sum += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		Sum = ft_putnmb((n / 10), Sum);
		Sum = ft_putnmb((n % 10), Sum);
	}
	else
		Sum += ft_putchar(48 + n);
	return (Sum);
}

int	ft_putnmbX(unsigned int n, int Sum)
{
	char base[16] = "0123456789ABCDEF";
	if (n >= 16)
	{
		Sum = ft_putnmbX((n / 16), Sum);
		Sum = ft_putnmbX((n % 16), Sum);
	}
	else
		Sum += ft_putchar(base[n]);
	return (Sum);
}

int	ft_putnmbx(unsigned int n, int Sum)
{
	char base[16] = "0123456789abcdef";
	if (n >= 16)
	{
		Sum = ft_putnmbx((n / 16), Sum);
		Sum = ft_putnmbx((n % 16), Sum);
	}
	else
		Sum += ft_putchar(base[n]);
	return (Sum);
}

int	ft_putp(unsigned long long int n, int Sum)
{
	char base[16] = "0123456789abcdef";
	if (n >= 16)
	{
		Sum = ft_putp((n / 16), Sum);
		Sum = ft_putp((n % 16), Sum);
	}
	else
		Sum += ft_putchar(base[n]);
	return (Sum);
}

int	ft_pad(unsigned long long int n, int Sum)
{
	write(1, "0x", 2);
	Sum += 2;
	Sum = ft_putp(n, Sum);
	return (Sum);
}

int	type(va_list args, const char *string, int Sum, int x)
{
	char *ss;

	if (string[x] == 'c')
		Sum += ft_putchar(va_arg(args, int));
	else if (string[x] == 's')
	{
		ss = va_arg(args, char *);
		if (ss == NULL)
			Sum = ft_putstring("(null)", Sum);
		else if (ss != NULL)
			Sum = ft_putstring(ss, Sum);
	}
	else if (string[x] == 'd' || string[x] == 'i')
		Sum = ft_putnmb(va_arg(args, int), Sum);
	else if (string[x] == 'u')
		Sum = ft_putnmbu(va_arg(args, unsigned int), Sum);
	else if (string[x] == '%')
		Sum += ft_putchar('%');
	else if (string[x] == 'x')
		Sum = ft_putnmbx(va_arg(args, unsigned int), Sum);
	else if (string[x] == 'X')
		Sum = ft_putnmbX(va_arg(args, unsigned int), Sum);
	else if (string[x] == 'p')
		Sum = ft_pad(va_arg(args, unsigned long long int), Sum);
	return (Sum);
}

int ft_printf(const char *string, ...)
{
	int		Sum;
	int		arcount;
	va_list	args;
	int		x;

	va_start(args, string);
	arcount = 0;
	x = -1;
	Sum = 0;
	while (string[++x] != 0)
	{
		if (string[x] == '%')
			Sum = type(args, string, Sum, ++x);
		else
			Sum += ft_putchar(string[x]);
	}
	va_end(args);
	return (Sum);
}

/*
int main(void)
{
	int x;
	unsigned int *p;
	char c = 'x';
	char *sn;
	char s[7] = " bella";
	unsigned int y;
	unsigned int z;

	sn = NULL;
	z = 42;
	y = -10;
	p = &z;
//	x = ft_printf("ciao%c%c%c%c", c, c, c, c);
//	x = ft_printf("ciao%s%c%c\n", s, c, c);
//	x = ft_printf("ciao %% %d %s %i %u %d \n", 2147483647, s, 101, y, y);
//	x = ft_printf("ciao %d %s %u %i\n", 10101010, s, y);
//	x = ft_printf("%X\n", 180);
//	x = ft_printf("%p\n", &z);
	x = ft_printf("%s\n", sn);
	printf("n ft: %d\n", x);
//	x = printf("ciao%c%c%c%c", c, c, c, c);
//	x = printf("ciao%s%c%c\n", s, c, c);
//	x = printf("ciao %d %s %u %i\n", 10101010, s, y);
//	x = printf("ciao %% %d %s %i %u %d \n", 2147483647, s, 101, y, y);
//	x = printf("%X\n", 180);
//	x = printf("%p\n", &z);
	x = printf("%s\n", sn);
	printf("n pf: %d\n", x);
}
*/
