/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:15:14 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/25 20:23:41 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

// #include <stdio.h>
// #include <bsd/string.h> //flag -lbsd
//
// int	main(void)
// {
// 	size_t	n;
// 	char	*src;
// 	char	dest1[16];
// 	char	dest3[16];
//
// 	src = "012345678912345";
// 	n = 15;
// 	printf("%zu\n", ft_strlcpy(dest3, src, n));
// 	printf("%zu\n", strlcpy(dest1, src, n));
// 	printf("S: %s\nD1: %s\nD2: %s\n", src, dest1, dest3);
// 	return (0);
// }