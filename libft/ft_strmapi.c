/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:43:55 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/28 21:11:11 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*dest;

	size = ft_strlen(s);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s[++i])
		dest[i] = f(i, s[i]);
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// 
// char	test(unsigned int i, char c)
// {
// 	i = 0;
// 	c = 0;
// 	return 'I';
// }
// 
// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("kl", test));
// 	return (0);
// }