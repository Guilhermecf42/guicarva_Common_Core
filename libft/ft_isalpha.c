/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:14:43 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/26 20:58:10 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	printf("%i\n", ft_isalnum('7'));
// 	printf("%i\n", ft_isalnum('d'));
// 	printf("%i\n", ft_isalnum('G'));
// 	printf("%i\n", ft_isalnum('\t'));
// 	printf("%i\n", ft_isalnum(130));
// 	return (0);
// }