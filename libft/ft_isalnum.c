/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:11:58 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/25 20:24:04 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
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