/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:12:21 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:50:24 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	printf("%i\n", ft_isascii('7'));
// 	printf("%i\n", ft_isascii('d'));
// 	printf("%i\n", ft_isascii('G'));
// 	printf("%i\n", ft_isascii('\t'));
// 	printf("%i\n", ft_isascii(130));
// 	return (0);
// }