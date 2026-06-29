/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 21:30:10 by guilh             #+#    #+#             */
/*   Updated: 2026/06/24 16:49:18 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_stack	*current;
	int		min_val;
	int		min_pos;
	int		pos;

	if (!stack)
		return (0);
	current = stack;
	min_val = current->index;
	min_pos = 0;
	pos = 0;
	while (1)
	{
		if (current->index < min_val)
		{
			min_val = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	t_stack	*current;
	int		max_val;
	int		max_pos;
	int		pos;

	if (!stack)
		return (0);
	current = stack;
	max_val = current->index;
	max_pos = 0;
	pos = 0;
	while (1)
	{
		if (current->index > max_val)
		{
			max_val = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (max_pos);
}

int	get_target_a_pos(t_stack *a, int index_b)
{
	t_stack	*current;
	int		pos;
	int		target_pos;
	long	closest_bigger;

	current = a;
	pos = 0;
	target_pos = 0;
	closest_bigger = 2147483648LL;
	while (1)
	{
		if (current->index > index_b && current->index < closest_bigger)
		{
			closest_bigger = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
		if (current == a)
			break ;
	}
	if (closest_bigger == 2147483648LL)
		return (get_min_pos(a));
	return (target_pos);
}

int	get_target_b_pos(t_stack *b, int index_a)
{
	t_stack	*current;
	int		pos;
	int		target_pos;
	long	closest_smaller;

	current = b;
	pos = 0;
	target_pos = 0;
	closest_smaller = -2147483649LL;
	while (1)
	{
		if (current->index < index_a && current->index > closest_smaller)
		{
			closest_smaller = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
		if (current == b)
			break ;
	}
	if (closest_smaller == -2147483649LL)
		return (get_max_pos(b));
	return (target_pos);
}

void	execute_move(t_stack **a, t_stack **b, int *best, t_bench *bench)
{
	int	size[2];

	size[A] = ft_stack_size(*a);
	size[B] = ft_stack_size(*b);
	if (best[A] <= size[A] / 2 && best[B] <= size[B] / 2)
	{
		while (best[A] > 0 && best[B] > 0)
		{
			rr(a, b, bench);
			best[A]--;
			best[B]--;
		}
	}
	else if (best[A] > size[A] / 2 && best[B] > size[B] / 2)
	{
		while (best[A] < size[A] && best[B] < size[B])
		{
			rrr(a, b, bench);
			best[A]++;
			best[B]++;
		}
	}
	rotate_single_a(a, best[A], size[A], bench);
	rotate_single_b(b, best[B], size[B], bench);
	pb(a, b, bench);
}
