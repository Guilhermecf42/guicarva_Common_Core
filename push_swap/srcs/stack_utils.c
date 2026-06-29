/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:57:04 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:40:22 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_circular_newnode(int value)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->index = -1;
	newnode->next = newnode;
	newnode->prev = newnode;
	return (newnode);
}

void	ft_circular_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = (*lst)->prev;
	last->next = new_node;
	new_node->prev = last;
	new_node->next = *lst;
	(*lst)->prev = new_node;
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*current;
	int		size;

	if (!stack)
		return (0);
	size = 0;
	current = stack;
	while (1)
	{
		size++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (size);
}

static int	get_index(t_stack *stack, int value)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack;
	while (1)
	{
		if (current->value < value)
			index++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (index);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	current = stack;
	while (1)
	{
		current->index = get_index(stack, current->value);
		current = current->next;
		if (current == stack)
			break ;
	}
}
