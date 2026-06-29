/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:50:31 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/15 22:25:22 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pointer(unsigned long nbr)
{
	int		size;
	char	*base;

	base = "0123456789abcdef";
	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_pointer(nbr / 16);
	ft_putchar(base[nbr % 16]);
	size++;
	return (size);
}
