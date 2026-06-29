/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:14:21 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/22 22:03:22 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*c_src;
	unsigned char		*c_dest;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	c_src = (const unsigned char *)src;
	c_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	buffer[11] = "xxxxxxxxxa";
// 	char	dest1[20];
// 	char	dest2[20];
// 	size_t	len;
//
// 	len = 99;
// 	printf("%s\n", dest1);
// 	ft_memcpy(dest1, buffer, len);
// 	printf("%s\n", dest1);
// 	printf("\n");
// 	memcpy(dest2, buffer, len);
// 	printf("%s\n", dest2);
// 	return (0);
// }