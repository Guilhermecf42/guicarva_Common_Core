/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:37:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:13:42 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	if (tmp->prev)
		tmp->prev->next = NULL;
	while (tmp)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	*stack = NULL;
}

void	error_exit(t_stack **a, t_stack **b, char **args, char *line)
{
	if (args)
		free_args(args);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	if (line)
		free(line);
	ft_printf(2, "Error\n");
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*start;

	if (!stack)
		return (1);
	start = stack;
	while (stack->next != start)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int n)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (1)
	{
		if (current->value == n)
			return (1);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}
