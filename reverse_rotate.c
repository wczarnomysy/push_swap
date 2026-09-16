/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:33:05 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/16 21:22:37 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, t_op *op)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	(*a)->prev = last;
	*a = last;
	if (op)
	{
		op->count[OP_RRA] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, t_op *op)
{
	t_node	*prev;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	last->prev = NULL;
	(*b)->prev = last;
	*b = last;
	if (op)
	{
		op->count[OP_RRB] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rra(a, NULL);
	rrb(b, NULL);
	if (op)
	{
		op->count[OP_RRR] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "rrr\n", 4);
}
