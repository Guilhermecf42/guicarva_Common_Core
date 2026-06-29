/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 21:50:31 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/15 21:20:29 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	int		size;

	size = 0;
	if (nbr >= 16)
		size = size + ft_putnbr_hexa(nbr / 16, base);
	ft_putchar(base[nbr % 16]);
	size++;
	return (size);
}
