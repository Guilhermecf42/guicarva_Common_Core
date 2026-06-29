/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 20:15:14 by guicarva          #+#    #+#             */
/*   Updated: 2026/04/25 20:02:20 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	if (!nmemb || !size)
		return (ptr);
	ft_bzero(ptr, total);
	return (ptr);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	int	*ptr1;
// 	int	*ptr2;
// 	int	i;
// 	int	n;
//
// 	n = 5;
// 	ptr1 = (int *)calloc(n, sizeof(ptr1));
// 	if (ptr1 == NULL)
// 		return (0);
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%i", ptr1[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(ptr1);
//
// 	ptr2 = (int *)ft_calloc(n, sizeof(ptr2));
// 	if (ptr2 == NULL)
// 		return (0);
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf("%i", ptr2[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	free(ptr2);
// 	return (0);
// }