/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:42:25 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 07:35:03 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] && s)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_malloc_words(char **words, const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	count = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		if ((s[i] == c && i > 0 && s[i - 1] != c)
			|| (s[i] != c && s[i + 1] == '\0'))
		{
			words[j] = malloc(sizeof(char) * (count + 1));
			if (!words[j])
				return (NULL);
			count = 0;
			j++;
		}
		i++;
	}
	return (words);
}

static char	**ft_cpy_words(char **words, const char *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
			words[x][y++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			words[x][y] = '\0';
		if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			words[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (words);
}

static char	**ft_free_all(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		words[i] = NULL;
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	wordcount;

	if (!s)
	{
		words = malloc(sizeof(char *) * 1);
		if (!words)
			return (NULL);
		*words = NULL;
		return (words);
	}
	wordcount = ft_count_words(s, c);
	words = malloc(sizeof(char *) * (wordcount + 1));
	if (!words)
		return (NULL);
	if (ft_malloc_words(words, s, c))
	{
		ft_cpy_words(words, s, c);
		words[wordcount] = NULL;
	}
	else
		words = ft_free_all(words);
	return (words);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	**res;
// 	size_t	i;
// 
// 	res = ft_split("ad  adsa  ad", ' ');
// 	i = 0;
// 	while (res[i])
// 	{
// 		printf("%s\n", res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }