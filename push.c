/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:36:08 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/16 21:21:29 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b, t_op *op)
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
	if (op)
	{
		op->count[OP_PA] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, t_op *op)
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
	if (op)
	{
		op->count[OP_PB] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "pb\n", 3);
}
