/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 20:44:43 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/28 21:52:24 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		f(i, &s[i]);
}

// #include <stdio.h>
//
// void	test(unsigned int i, char *c)
// {
// 	i = 0;
// 	*c = ft_tolower(*c);
// }
//
// int	main(void)
// {
// 	char	src[] = "BOm DIa";
//
// 	ft_striteri(src, test);
// 	printf("%s\n", src);
// 	return (0);
// }