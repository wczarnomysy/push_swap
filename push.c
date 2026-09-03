/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:36:08 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b, int print, t_op *op)
{
	t_node	*tmp;

	if (!b || !*b || !a)
		return ;
	tmp = *b;
	*b = tmp->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	do_op(op, OP_PA, print);
}

void	pb(t_node **a, t_node **b, int print, t_op *op)
{
	t_node	*tmp;

	if (!a || !*a || !b)
		return ;
	tmp = *a;
	*a = tmp->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	do_op(op, OP_PB, print);
}
