/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:18:02 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/21 22:27:46 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// 
// int	main(void)
// {
// 	char	*buffer;
// 	size_t	len;
// 
// 	buffer = "mundolindo";
// 	len = 10;
// 	printf("%s\n", (char *)ft_memchr(buffer,80, len));
// 	printf("%s\n", (char *)memchr(buffer, 80, len));
// 	return (0);
// }