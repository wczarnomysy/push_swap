/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 20:13:43 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, int print, t_op *op)
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
	do_op(op, OP_RA, print);
}

void	rb(t_node **b, int print, t_op *op)
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
	do_op(op, OP_RB, print);
}

void	rr(t_node **a, t_node **b, int print, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	ra(a, 0, NULL);
	rb(b, 0, NULL);
	do_op(op, OP_RR, print);
}
