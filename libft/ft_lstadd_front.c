/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:57:40 by guicarva          #+#    #+#             */
/*   Updated: 2026/05/02 19:12:37 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
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
// 	n0.next = &n1;
// 	n0.content = "1";
// 	n1.next = &n2;
// 	n1.content = "2";
// 	n2.next = NULL;
// 	n2.content = "3";
// 	new.next = NULL;
// 	new.content = "0";
// 
// 	lst = &n0;
// 	printf("lst: %s\n", (char *)lst->content);
// 	printf("\n");
// 	ft_lstadd_front(&lst, &new);
// 	printf("lst: %s\n", (char *)lst->content);
// 	return (0);
// }