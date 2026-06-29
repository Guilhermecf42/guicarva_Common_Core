/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:47:17 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:13:50 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a, t_bench *bench)
{
	if ((*a)->prev == *a)
		return ;
	*a = (*a)->prev;
	if (bench)
	{
		bench->total_ops++;
		bench->rra++;
		ft_printf(1, "rra\n");
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	if ((*b)->prev == *b)
		return ;
	*b = (*b)->prev;
	if (bench)
	{
		bench->total_ops++;
		bench->rrb++;
		ft_printf(1, "rrb\n");
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((*a)->prev == *a || (*b)->prev == *b)
		return ;
	*a = (*a)->prev;
	*b = (*b)->prev;
	if (bench)
	{
		bench->total_ops++;
		bench->rrr++;
		ft_printf(1, "rrr\n");
	}
}
