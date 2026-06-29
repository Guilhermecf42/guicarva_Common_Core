/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:15:48 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/25 20:12:22 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = 0;
	while (src[s_len])
		s_len++;
	d_len = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	if (d_len == size)
		return (size + s_len);
	i = d_len;
	j = 0;
	while (src[j] && (i + 1) < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}

// #include <stdio.h>
// #include <bsd/string.h> //flag -lbsd
//
// int	main(void)
// {
// 	char	*buffer1;
// 	char	*buffer2;
// 	char	dest1[20] = "mundo";
// 	char	dest2[20] = "mundo";
// 	size_t	size;
//
// 	buffer1 = "12345";
// 	buffer2 = "12345";
// 	size = 11;
// 	printf("D1: %s\nD2: %s\nB1: %s\nB2: %s\n", dest1, dest2, buffer1, buffer2);
// 	printf("%zu\n", ft_strlcat(dest1, buffer1, size));
// 	printf("%zu\n", strlcat(dest2, buffer2, size));
// 	printf("D1: %s\nD2: %s\n", dest1, dest2);
// 	return (0);
// }