/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:57:04 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 09:57:30 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	char	*str;
// 	t_list	*node;
// 
// 	str = "good day";
// 	node = ft_lstnew(str);
// 	printf("%s\n", (char *)node->content);
// 	free(node);
// 	return (0);
// }