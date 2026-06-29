/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:27:11 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:13:51 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a, t_bench *bench)
{
	if ((*a)->next == *a)
		return ;
	*a = (*a)->next;
	if (bench)
	{
		bench->total_ops++;
		bench->ra++;
		ft_printf(1, "ra\n");
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	if ((*b)->next == *b)
		return ;
	*b = (*b)->next;
	if (bench)
	{
		bench->total_ops++;
		bench->rb++;
		ft_printf(1, "rb\n");
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if ((*a)->next == *a || (*b)->next == *b)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
	if (bench)
	{
		bench->total_ops++;
		bench->rr++;
		ft_printf(1, "rr\n");
	}
}
