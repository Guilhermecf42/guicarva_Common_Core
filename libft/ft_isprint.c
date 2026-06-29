/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:12:42 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:50:35 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	printf("%i\n", ft_isprint('7'));
// 	printf("%i\n", ft_isprint('d'));
// 	printf("%i\n", ft_isprint('G'));
// 	printf("%i\n", ft_isprint('\t'));
// 	printf("%i\n", ft_isprint(130));
// 	return (0);
//}