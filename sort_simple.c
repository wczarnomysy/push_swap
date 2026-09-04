/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:06:20 by wczarnom          #+#    #+#             */
/*   Updated: 2026/09/04 18:33:02 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Bring the current minimum of a to the top, then push it to b. */
void	push_min_to_b(t_node **a, t_node **b, int len, t_op *op)
{
	t_node	*min;
	int		pos;

	min = find_min(*a);
	pos = node_pos(*a, min);
	move_to_top(a, pos, len, op);
	pb(a, b, op);
}

/*
** Selection sort in the push_swap model: O(n^2) operations. Repeatedly extract
** the minimum into b, then pour b back onto a (already ascending on top).
*/
void	sort_simple(t_node **a, t_node **b, t_op *op)
{
	int	len;

	len = ft_lstsize(*a);
	while (len > 0)
	{
		push_min_to_b(a, b, len, op);
		len--;
	}
	while (*b)
		pa(a, b, op);
}
