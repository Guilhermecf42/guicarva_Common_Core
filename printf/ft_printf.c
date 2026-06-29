/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:14:44 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/17 14:55:42 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkadd(void *add)
{
	if (!add)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_pointer((unsigned long long)add) + 2);
}

static int	check_flags(va_list args, int c)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(args, int));
	else if (c == 's')
		res = ft_putstr(va_arg(args, char *));
	else if (c == '%')
		res = ft_putchar('%');
	else if (c == 'i' || c == 'd')
		res = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		res = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'X')
		res = ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		res = ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'p')
		res = ft_checkadd(va_arg(args, void *));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		res;

	va_start(args, format);
	res = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			res = res + check_flags(args, format[++i]);
		else
			res = res + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
