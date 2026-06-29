/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:50:31 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:05:03 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_putchr(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_h(unsigned long nbr, char *base, int fd)
{
	int	size;

	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_h(nbr / 16, base, fd);
	write(fd, &base[nbr % 16], 1);
	size++;
	return (size);
}

int	ft_putnbr_u(unsigned int n, int fd)
{
	char	nbr;
	int		size;

	size = 0;
	if (n >= 10)
		size = size + ft_putnbr_u(n / 10, fd);
	nbr = (n % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	return (size);
}

int	ft_putnbr(long n, int fd)
{
	char	nbr;
	int		size;

	size = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		size++;
	}
	if (n >= 10)
		size = size + ft_putnbr(n / 10, fd);
	nbr = (n % 10) + 48;
	write(fd, &nbr, 1);
	size++;
	return (size);
}

int	ft_putstr(char *s, int fd)
{
	int	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
