/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 18:35:17 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/16 21:21:04 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a, t_op *op)
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
	if (op)
	{
		op->count[OP_SA] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, t_op *op)
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
	if (op)
	{
		op->count[OP_SB] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, t_op *op)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	sa(a, NULL);
	sb(b, NULL);
	if (op)
	{
		op->count[OP_SS] += 1;
		op->total += 1;
	}
	if (op->print)
		write(1, "ss\n", 3);
}
