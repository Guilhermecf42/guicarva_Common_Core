/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:58:23 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 17:35:28 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	n0;
// 	t_list	n1;
// 	t_list	n2;
// 	t_list	n3;
// 
// 	lst = &n0;
// 	n0.content = "0";
// 	n0.next = &n1;
// 	n1.content = "1";
// 	n1.next = &n2;
// 	n2.content = "2";
// 	n2.next = &n3;
// 	n3.content = "3";
// 	n3.next = NULL;
// 
// 	printf("size: %i\n", ft_lstsize(lst));
// 	return (0);
// }