/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:22:16 by guilh             #+#    #+#             */
/*   Updated: 2026/06/24 17:14:39 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_single_a(t_stack **a, int pos_a, int size_a, t_bench *bench)
{
	if (pos_a <= size_a / 2)
		while (pos_a-- > 0)
			ra(a, bench);
	else
		while (pos_a++ < size_a)
			rra(a, bench);
}

void	rotate_single_b(t_stack **b, int pos_b, int size_b, t_bench *bench)
{
	if (pos_b <= size_b / 2)
		while (pos_b-- > 0)
			rb(b, bench);
	else
		while (pos_b++ < size_b)
			rrb(b, bench);
}

static int	total_cost(int *pos, int *size)
{
	int	rr;
	int	rrr;
	int	mix1;
	int	mix2;
	int	min;

	if (pos[A] > pos[B])
		rr = pos[A];
	else
		rr = pos[B];
	if ((size[A] - pos[A]) > (size[B] - pos[B]))
		rrr = size[A] - pos[A];
	else
		rrr = size[B] - pos[B];
	mix1 = pos[A] + (size[B] - pos[B]);
	mix2 = (size[A] - pos[A]) + pos[B];
	min = rr;
	if (rrr < min)
		min = rrr;
	if (mix1 < min)
		min = mix1;
	if (mix2 < min)
		min = mix2;
	return (min);
}

static void	find_cheapest(t_stack **a, t_stack **b, t_bench *bench, int *size)
{
	t_stack	*current;
	int		min_ops;
	int		best[2];
	int		pos[2];

	current = *a;
	pos[A] = 0;
	min_ops = 2147483647;
	while (1)
	{
		pos[B] = get_target_b_pos(*b, current->index);
		if (total_cost(pos, size) < min_ops)
		{
			min_ops = total_cost(pos, size);
			best[A] = pos[A];
			best[B] = pos[B];
		}
		if (min_ops == 0)
			break ;
		pos[A]++;
		current = current->next;
		if (current == *a)
			break ;
	}
	execute_move(a, b, best, bench);
}

void	turk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	target_a;
	int	min_pos;
	int	size[2];

	if (ft_stack_size(*a) > 3)
		pb(a, b, bench);
	if (ft_stack_size(*a) > 3)
		pb(a, b, bench);
	while (ft_stack_size(*a) > 3)
	{
		size[A] = ft_stack_size(*a);
		size[B] = ft_stack_size(*b);
		find_cheapest(a, b, bench, size);
	}
	simple_3low(a, bench);
	while (*b)
	{
		target_a = get_target_a_pos(*a, (*b)->index);
		rotate_single_a(a, target_a, ft_stack_size(*a), bench);
		pa(a, b, bench);
	}
	min_pos = get_min_pos(*a);
	rotate_single_a(a, min_pos, ft_stack_size(*a), bench);
}
