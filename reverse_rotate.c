/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:33:05 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, int print, t_op *op)
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
	do_op(op, OP_RRA, print);
}

void	rrb(t_node **b, int print, t_op *op)
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
	do_op(op, OP_RRB, print);
}

void	rrr(t_node **a, t_node **b, int print, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rra(a, 0, NULL);
	rrb(b, 0, NULL);
	do_op(op, OP_RRR, print);
}
