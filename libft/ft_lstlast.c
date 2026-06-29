/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:58:45 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 19:35:59 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*current;
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
// 	current = lst;
// 
// 	printf("lst: %p\n", current);
// 	printf("n0: %p\n", &n0);
// 	printf("\n");
// 	current = ft_lstlast(lst);
// 	printf("lst: %p\n", current);
// 	printf("n3: %p\n", &n3);
// 	return (0);
// }