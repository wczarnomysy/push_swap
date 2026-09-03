/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:58:33 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Dispatch to the strategy requested on the command line. A forced flag
** always runs its own algorithm (any input size); --adaptive (the default)
** picks an algorithm from the disorder index.
*/
void	sort_stack(t_node **a, t_node **b, int size, t_op *op)
{
	if (size < 2 || ft_is_sorted(*a))
	{
		if (op->complexity == COMPLEXITY_UNKNOWN)
			op->complexity = COMPLEXITY_SMALL;
		return ;
	}
	if (op->flag == FLAG_SIMPLE)
	{
		op->complexity = COMPLEXITY_SIMPLE;
		sort_simple(a, b, op);
	}
	else if (op->flag == FLAG_MEDIUM)
	{
		op->complexity = COMPLEXITY_MEDIUM;
		sort_medium(a, b, op);
	}
	else if (op->flag == FLAG_COMPLEX)
	{
		op->complexity = COMPLEXITY_COMPLEX;
		radix_sort(a, b, op);
	}
	else
		adaptive_sort(a, b, op->disorder, op);
}
