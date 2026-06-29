/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 23:24:09 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/22 23:13:49 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_part2(t_stack **dest, t_stack *node_push)
{
	t_stack	*last_dest;

	if (*dest == NULL)
	{
		*dest = node_push;
		node_push->next = *dest;
		node_push->prev = *dest;
	}
	else
	{
		last_dest = (*dest)->prev;
		node_push->next = *dest;
		node_push->prev = last_dest;
		last_dest->next = node_push;
		(*dest)->prev = node_push;
		*dest = node_push;
	}
}

static void	push(t_stack **orin, t_stack **dest)
{
	t_stack	*node_push;
	t_stack	*last_orin;

	if (!orin || !*orin)
		return ;
	node_push = *orin;
	if (node_push->next == node_push)
		*orin = NULL;
	else
	{
		last_orin = node_push->prev;
		*orin = node_push->next;
		(*orin)->prev = last_orin;
		last_orin->next = *orin;
	}
	push_part2(dest, node_push);
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	if (bench)
	{
		bench->total_ops++;
		bench->pa++;
		ft_printf(1, "pa\n");
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	if (bench)
	{
		bench->total_ops++;
		bench->pb++;
		ft_printf(1, "pb\n");
	}
}
