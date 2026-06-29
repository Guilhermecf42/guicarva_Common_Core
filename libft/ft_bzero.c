/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:35:52 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/21 22:22:25 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

// #include <stdio.h>
// #include <strings.h>
// 
// int	main(void)
// {
// 	char	buffer1[10] = "xxxxxxxxxx";
// 	char	buffer2[10] = "xxxxxxxxxx";
// 	size_t	len;
// 	size_t	i;
// 	size_t	j;
// 
// 	len = 10;
// 	printf("buffer1 original: %s\n", buffer1);
// 	ft_bzero(buffer1, len);
// 	printf("buffer1 alterado: ");
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (buffer1[i] == 0)
// 			printf("0");
// 		else
// 			printf("%s", &buffer1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("buffer2 original: %s\n", buffer2);
// 	bzero(buffer2, len);
// 	printf("buffer2 alterado: ");
// 	j = 0;
// 	while (j < len)
// 	{
// 		if (buffer2[j] == 0)
// 			printf("0");
// 		else
// 			printf("%s", &buffer2[j]);
// 		j++;
// 	}
// 	printf("\n");
// 	return (0);
// }