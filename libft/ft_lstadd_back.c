/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:59:18 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 20:22:40 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// #include <stdio.h>
// 
// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	n0;
// 	t_list	n1;
// 	t_list	n2;
// 	t_list	new;
// 
// 	lst = &n0;
// 	n0.content = "0";
// 	n0.next = &n1;
// 	n1.content = "1";
// 	n1.next = &n2;
// 	n2.content = "2";
// 	n2.next = NULL;
// 	new.content = "3";
// 	new.next = NULL;
// 
// 	printf("n0: %s\n", (char *)n0.next);
// 	printf("n1: %s\n", (char *)n1.next);
// 	printf("n2: %s\n", (char *)n2.next);
// 	printf("n3: %s\n", (char *)new.next);
// 	printf("\n");
// 	ft_lstadd_back(&lst, &new);
// 	printf("n0: %s\n", (char *)n0.next);
// 	printf("n1: %s\n", (char *)n1.next);
// 	printf("n2: %s\n", (char *)n2.next);
// 	printf("n3: %s\n", (char *)new.next);
// 	return (0);
// }