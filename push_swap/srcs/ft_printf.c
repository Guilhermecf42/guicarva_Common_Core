/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 22:14:44 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:05:13 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_putnbr_2digits(unsigned int n, int fd)
{
	char	nbr;
	int		size;

	size = 0;
	nbr = ((n / 10) % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	nbr = (n % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	return (size);
}

static int	ft_putnbr_f(double n, int fd)
{
	long			whole;
	unsigned int	fract;
	int				size;

	size = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		size++;
	}
	whole = (long)n;
	fract = (unsigned int)((n - (double)whole) * 100.0 + 0.5);
	if (fract >= 100)
	{
		whole += 1;
		fract = 0;
	}
	size += ft_putnbr(whole, fd);
	write(fd, ".", 1);
	size++;
	size += ft_putnbr_2digits(fract, fd);
	return (size);
}

static int	ft_checkadd(void *add, int fd)
{
	if (!add)
		return (ft_putstr("(nil)", fd));
	ft_putstr("0x", fd);
	return (ft_putnbr_h((unsigned long long)add, "0123456789abcdef", fd) + 2);
}

static int	check_flags(va_list args, int c, int fd)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchr(va_arg(args, int), fd);
	else if (c == 's')
		res = ft_putstr(va_arg(args, char *), fd);
	else if (c == '%')
		res = write(fd, "%", 1);
	else if (c == 'i' || c == 'd')
		res = ft_putnbr(va_arg(args, int), fd);
	else if (c == 'u')
		res = ft_putnbr_u(va_arg(args, unsigned int), fd);
	else if (c == 'f')
		res = ft_putnbr_f(va_arg(args, double), fd);
	else if (c == 'X')
		res = ft_putnbr_h(va_arg(args, unsigned int), "0123456789ABCDEF", fd);
	else if (c == 'x')
		res = ft_putnbr_h(va_arg(args, unsigned int), "0123456789abcdef", fd);
	else if (c == 'p')
		res = ft_checkadd(va_arg(args, void *), fd);
	return (res);
}

int	ft_printf(int fd, const char *format, ...)
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
		{
			i++;
			res = res + check_flags(args, format[i], fd);
		}
		else
			res = res + write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
