/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:01:17 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/02/08 16:10:21 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstring(char *astring, int Sum);
int	ft_putnmbu(unsigned int n, int Sum);
int	ft_putnmb(int n, int Sum);
int	ft_putnmbcx(unsigned int n, int Sum, char *base);
int	ft_putnmbx(unsigned int n, int Sum, char *base);
int	ft_putp(unsigned long long int n, int Sum, char *base);
int	ft_pad(unsigned long long int n, int Sum, char *base);
int	type(va_list args, const char *string, int Sum, int x);
int	ft_printf(const char *string, ...);
#endif
