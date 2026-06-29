/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:11:27 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:50:29 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	printf("%i\n", ft_isdigit('7'));
// 	printf("%i\n", ft_isdigit('d'));
// 	printf("%i\n", ft_isdigit('G'));
// 	printf("%i\n", ft_isdigit('\t'));
// 	printf("%i\n", ft_isdigit(130));
// 	return (0);
// }