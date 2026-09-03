/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:35:17 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, int print, t_op *op)
{
	int	tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	do_op(op, OP_SA, print);
}

void	sb(t_node **b, int print, t_op *op)
{
	int	tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	tmp = (*b)->index;
	(*b)->index = (*b)->next->index;
	(*b)->next->index = tmp;
	do_op(op, OP_SB, print);
}

void	ss(t_node **a, t_node **b, int print, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	sa(a, 0, NULL);
	sb(b, 0, NULL);
	do_op(op, OP_SS, print);
}
