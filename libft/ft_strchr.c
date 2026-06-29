/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:17:04 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:51:54 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	nc;

	i = -1;
	nc = (char)c;
	while (s[++i])
		if (s[i] == nc)
			return ((char *)&s[i]);
	if (nc == '\0')
		return ((char *)&s[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main(void)
// {
// 	char	buffer[32] = "test";
//
// 	printf("%s\n", ft_strchr(buffer, '\0'));
// 	printf("\n");
// 	printf("%s\n", strchr(buffer, '\0'));
// 	return (0);
// }