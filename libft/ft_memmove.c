/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:14:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:51:25 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*c_src;
	unsigned char		*c_dest;

	if (!dest && !src)
		return (NULL);
	c_src = (const unsigned char *)src;
	c_dest = (unsigned char *)dest;
	if (c_dest < c_src)
	{
		while (n--)
			*c_dest++ = *c_src++;
	}
	else if (c_dest > c_src)
	{
		while (n--)
			c_dest[n] = c_src[n];
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// 
// int	main(void)
// {
// 	char	buffer[11] = "xxxxxxxxxa";
// 	char	dest2[20] =  "1234567890123456789";
// 	char	dest1[20] =  "1234567890123456789";
// 	size_t	len;
// 
// 	len = 9;
// 	printf("%s\n%s\n%s\n\n", buffer, dest1, dest2);
// 
// 	ft_memmove(dest1, buffer, len);
// 	printf("%s\n", dest1);
// 	printf("\n");
// 	memmove(dest2, buffer, len);
// 	printf("%s\n", dest2);
// 	return (0);
// }