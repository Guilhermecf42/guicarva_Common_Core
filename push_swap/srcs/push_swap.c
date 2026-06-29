/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:53:36 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:17:47 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	start_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->active = 0;
	bench->algorithm = 0;
	bench->strategy = "Adaptive";
	bench->total_ops = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	print_bench(t_bench *bench)
{
	ft_printf(2, "[bench] disorder:  %f%%\n", bench->disorder);
	ft_printf(2, "[bench] strategy:  %s\n", bench->strategy);
	ft_printf(2, "[bench] total_ops:  %i\n", bench->total_ops);
	ft_printf(2, "[bench] sa:  %i  sb:  %i  ss:  ", bench->sa, bench->sb);
	ft_printf(2, "%i  pa:  %i  pb:  %i\n", bench->ss, bench->pa, bench->pb);
	ft_printf(2, "[bench] ra:  %i  rb:  %i  rr:  ", bench->ra, bench->rb);
	ft_printf(2, "%i  rra:  %i  rrb:  %i", bench->rr, bench->rra, bench->rrb);
	ft_printf(2, "  rrr:  %i\n", bench->rrr);
}

static double	compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;
	long	mistakes;
	long	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (1)
	{
		next = current->next;
		while (next != stack)
		{
			total_pairs++;
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		if (current == stack->prev)
			break ;
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)total_pairs);
}

static void	push_swap(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = ft_stack_size(*a);
	if (size <= 3)
		simple_3low(a, bench);
	else if (size <= 5 || bench->disorder == 100.0)
		sort_simple(a, b, bench);
	else if (bench->algorithm == 1)
		turk_sort(a, b, bench);
	else if (bench->algorithm == 2)
		k_sort(a, b, bench);
	else if (bench->algorithm == 3)
		radix_sort(a, b, bench);
	else
	{
		if (bench->disorder < 20.0)
			turk_sort(a, b, bench);
		else if (bench->disorder < 50.0)
			k_sort(a, b, bench);
		else
			radix_sort(a, b, bench);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	start_bench(&bench);
	a = parse_args(argc, argv, &bench);
	b = NULL;
	bench.disorder = compute_disorder(a) * 100.0;
	if (!bench.algorithm && bench.disorder < 20.0)
		bench.strategy = "Adaptive / O(n²)";
	else if (!bench.algorithm && bench.disorder < 50.0)
		bench.strategy = "Adaptive / O(n√n)";
	else if (!bench.algorithm && bench.disorder >= 50.0)
		bench.strategy = "Adaptive / O(n log n)";
	assign_indexes(a);
	push_swap(&a, &b, &bench);
	if (bench.active)
		print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
