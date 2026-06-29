/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:02:25 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:02:45 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	if (n <= 0)
		return (0);
	while (i <= n / i)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i - 1);
}

static void	push_to_b(t_stack **a, t_stack **b, t_bench *bench, int total_size)
{
	int	chunk_size;
	int	i;

	chunk_size = ((ft_sqrt(total_size) * 3) / 2);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

static void	push_to_a(t_stack **a, t_stack **b, t_bench *bench, int total_size)
{
	t_stack	*current;
	int		current_size;
	int		index_max;
	int		pos;

	index_max = total_size - 1;
	while (*b)
	{
		pos = 0;
		current = *b;
		while (current->index != index_max)
		{
			pos++;
			current = current->next;
		}
		current_size = index_max + 1;
		if (pos <= current_size / 2)
			while ((*b)->index != index_max)
				rb(b, bench);
		else
			while ((*b)->index != index_max)
				rrb(b, bench);
		pa(a, b, bench);
		index_max--;
	}
}

void	k_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	total_size;

	total_size = ft_stack_size(*a);
	push_to_b(a, b, bench, total_size);
	push_to_a(a, b, bench, total_size);
}
