/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:18:48 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/26 21:31:54 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
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
// 	len = 123;
// 	printf("%i\n", ft_memcmp(buffer1, buffer2, len));
// 	printf("\n");
// 	printf("%i\n", memcmp(buffer1, buffer2, len));
// 	return (0);
// }