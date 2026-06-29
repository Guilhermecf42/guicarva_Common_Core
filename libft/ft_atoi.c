/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:19:21 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:49:43 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;
	int	dest;

	i = 0;
	sinal = 1;
	dest = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sinal *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		dest = (dest * 10) + (nptr[i] - '0');
		i++;
	}
	return (dest * sinal);
}

// #include <stdio.h>
// #include <stdlib.h>
// 
// int	main(void)
// {
// 	printf("Certo: %i\n", ft_atoi("  	-123mmm"));
// 	printf("Errado: %i\n", ft_atoi("  	-+-123mmm"));
// 	printf("Certo: %i\n", ft_atoi("123"));
// 	printf("Errado: %i\n", ft_atoi("-n123"));
// 	printf("\n");
// 	printf("Certo: %i\n", atoi("  	-123mmm"));
// 	printf("Errado: %i\n", atoi("  	-+-123mmm"));
// 	printf("Certo: %i\n", atoi("123"));
// 	printf("Errado: %i\n", atoi("-n123"));
// 	return (0);
// }