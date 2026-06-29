/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:19:05 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/22 23:24:09 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		f = 0;
		while (little[f] == big[i + f] && (i + f) < len)
			if (little[++f] == '\0')
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char 	*str;
// 	char 	*to_find;
// 	size_t	size;
//
// 	str = "42 is very funny";
// 	to_find = "very";
// 	size = 9;
// 	printf("%s\n", ft_strnstr(str, to_find, size));
// 	return (0);
// }