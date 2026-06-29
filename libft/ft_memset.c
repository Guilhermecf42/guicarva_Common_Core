/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:13:35 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/21 22:54:43 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = c;
		str++;
		n--;
	}
	return ((void *)s);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	buffer1[10] = "xxxxxxxxxx";
// 	char	buffer2[10] = "xxxxxxxxxx";
// 	size_t	len;
//
// 	len = 10;
// 	printf("buffer1 original: %s\n", buffer1);
// 	ft_memset(buffer1, 98, len);
// 	printf("buffer1 alterado: %s\n", buffer1);
// 	printf("\n");
// 	printf("buffer2 original: %s\n", buffer2);
// 	memset(buffer2, 98, len);
// 	printf("buffer2 alterado: %s\n", buffer2);
// 	return (0);
// }