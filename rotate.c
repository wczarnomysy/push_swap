/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 20:13:43 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/16 21:19:55 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, t_op *op)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	if (op)
	{
		op->count[OP_RA] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, t_op *op)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	if (op)
	{
		op->count[OP_RB] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	ra(a, NULL);
	rb(b, NULL);
	if (op)
	{
		op->count[OP_RR] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "rr\n", 3);
}
