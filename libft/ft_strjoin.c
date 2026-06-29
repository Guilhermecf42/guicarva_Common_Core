/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:40:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/25 22:36:35 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	total;
	size_t	i;
	size_t	j;

	total = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (total + 1));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstr[i] = s1[i];
	j = -1;
	while (s2[++j])
		newstr[i++] = s2[j];
	newstr[i] = '\0';
	return (newstr);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
//
// 	s1 = "bom";
// 	s2 = "dia";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }