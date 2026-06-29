/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:41:44 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:55:02 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*newstr;
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_check(set, s1[end - 1]))
		end--;
	newstr = malloc(sizeof(char) * (end - start + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s1[start], end - start + 1);
	return (newstr);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*str;
// 	char	*set;
// 	char	*buffer;
//
// 	str = "";
// 	set = "";
// 	buffer = ft_strtrim(str, set);
// 	printf("%s\n", buffer);
// 	free(buffer);
// 	return (0);
// }