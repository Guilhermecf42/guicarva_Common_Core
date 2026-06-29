/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:47:23 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/14 22:39:10 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	char	nbr;
	int		size;

	size = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	if (n >= 10)
		size = size + ft_putnbr(n / 10);
	nbr = (n % 10) + 48;
	write(1, &nbr, 1);
	size++;
	return (size);
}
