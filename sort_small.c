/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:06:20 by wczarnom          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort exactly 3 nodes (by rank index) with at most 2 operations. */
static void	sort_three(t_node **a, t_op *op)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		sa(a, 1, op);
	else if (f > s && s > t)
	{
		sa(a, 1, op);
		rra(a, 1, op);
	}
	else if (f > s && f > t)
		ra(a, 1, op);
	else if (f < s && s > t && f < t)
	{
		sa(a, 1, op);
		ra(a, 1, op);
	}
	else if (f < s && s > t && f > t)
		rra(a, 1, op);
}

static void	sort_four(t_node **a, t_node **b, t_op *op)
{
	push_min_to_b(a, b, 4, op);
	sort_three(a, op);
	pa(a, b, 1, op);
}

static void	sort_five(t_node **a, t_node **b, t_op *op)
{
	push_min_to_b(a, b, 5, op);
	push_min_to_b(a, b, 4, op);
	sort_three(a, op);
	pa(a, b, 1, op);
	pa(a, b, 1, op);
}

/* Entry point for 2..5 elements (larger inputs never reach here). */
void	sort_small(t_node **a, t_node **b, t_op *op)
{
	int	len;

	len = ft_lstsize(*a);
	if (len <= 1 || ft_is_sorted(*a))
		return ;
	if (len == 2)
		sa(a, 1, op);
	else if (len == 3)
		sort_three(a, op);
	else if (len == 4)
		sort_four(a, b, op);
	else if (len == 5)
		sort_five(a, b, op);
}
