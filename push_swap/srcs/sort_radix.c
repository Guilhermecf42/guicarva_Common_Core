/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranca <gfranca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 23:12:50 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 17:18:21 by gfranca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack *a)
{
	t_stack	*current;
	int		max_index;
	int		bits;

	if (!a)
		return (0);
	max_index = a->index;
	current = a;
	while (1)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
		if (current == a)
			break ;
	}
	bits = 0;
	while ((max_index >> bits) > 0)
		bits++;
	return (bits);
}

static int	pays_off(t_stack *stack, int i)
{
	t_stack	*curr;
	int		one;
	int		zero;

	curr = stack;
	one = 0;
	zero = 0;
	while (1)
	{
		if (((curr->index >> i) & 1) == 1)
			one++;
		else
			zero++;
		curr = curr->next;
		if (curr == stack)
			break ;
	}
	if (one == 0 || zero == 0)
		return (1);
	return (0);
}

static void	process_a_bit(t_stack **a, t_stack **b, t_bench *bench, int i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_stack_size(*a);
	while (j < size)
	{
		if ((((*a)->index >> i) & 1) == 0)
			pb(a, b, bench);
		else
			ra(a, bench);
		j++;
	}
}

static void	process_b_bit(t_stack **a, t_stack **b, t_bench *bench, int i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_stack_size(*b);
	while (j < size)
	{
		if (((*b)->index >> (i + 1) & 1) == 1)
			pa(a, b, bench);
		else
			rb(b, bench);
		j++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	i;
	int	max_bits;

	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		if (is_sorted(*a))
			return ;
		if (pays_off(*a, i))
		{
			i++;
			continue ;
		}
		process_a_bit(a, b, bench, i);
		if (pays_off(*b, i + 1))
		{
			i++;
			continue ;
		}
		process_b_bit(a, b, bench, i);
		i++;
	}
	while (*b)
		pa(a, b, bench);
}
