/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:06:20 by wczarnom          #+#    #+#             */
/*   Updated: 2026/09/04 20:12:17 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a, t_op *op)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->index;
	s = (*a)->next->index;
	t = (*a)->next->next->index;
	if (f > s && s < t && f < t)
		sa(a, op);
	else if (f > s && s > t)
	{
		sa(a, op);
		rra(a, op);
	}
	else if (f > s && f > t)
		ra(a, op);
	else if (f < s && s > t && f < t)
	{
		sa(a, op);
		ra(a, op);
	}
	else if (f < s && s > t && f > t)
		rra(a, op);
}

static void	sort_four(t_node **a, t_node **b, t_op *op)
{
	push_min_to_b(a, b, 4, op);
	sort_three(a, op);
	pa(a, b, op);
}

static void	sort_five(t_node **a, t_node **b, t_op *op)
{
	push_min_to_b(a, b, 5, op);
	push_min_to_b(a, b, 4, op);
	sort_three(a, op);
	pa(a, b, op);
	pa(a, b, op);
}

void	sort_small(t_node **a, t_node **b, t_op *op)
{
	int	len;

	len = ft_lstsize(*a);
	if (len <= 1 || ft_is_sorted(*a))
		return ;
	if (len == 2)
		sa(a, op);
	else if (len == 3)
		sort_three(a, op);
	else if (len == 4)
		sort_four(a, b, op);
	else if (len == 5)
		sort_five(a, b, op);
}
