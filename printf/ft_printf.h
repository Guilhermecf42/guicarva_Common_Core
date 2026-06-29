/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 21:55:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/17 15:01:57 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putnbr_hexa(unsigned int nbr, char *base);
int	ft_putnbr_pointer(unsigned long nbr);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr(long n);
int	ft_putstr(char *s);

#endif