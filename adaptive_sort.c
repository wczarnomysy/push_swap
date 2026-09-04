/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:58:38 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/04 18:03:19 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b, float disorder, t_op *op)
{
	if (ft_lstsize(*a) <= 5)
	{
		op->complexity = COMPLEXITY_SMALL;
		sort_small(a, b, op);
	}
	else if (disorder < 0.2f)
	{
		op->complexity = COMPLEXITY_SIMPLE;
		sort_simple(a, b, op);
	}
	else if (disorder < 0.5f && disorder > 0.2f)
	{
		op->complexity = COMPLEXITY_MEDIUM;
		sort_medium(a, b, op);
	}
	else
	{
		op->complexity = COMPLEXITY_COMPLEX;
		radix_sort(a, b, op);
	}
}
