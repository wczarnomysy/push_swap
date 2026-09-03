/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:26:33 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ~sqrt(n) sized chunks: O(n*sqrt(n)) operations. */
static int	chunk_size_for(int n)
{
	int	r;

	r = 1;
	while (r * r < n)
		r++;
	if (n > 100)
		r = r * 2;
	return (r);
}

static t_node	*find_max_idx(t_node *b)
{
	t_node	*max;

	max = b;
	while (b)
	{
		if (b->index > max->index)
			max = b;
		b = b->next;
	}
	return (max);
}

/* Push every node whose rank falls in [lo, hi) from a into b. */
static void	send_chunk(t_node **a, t_node **b, int lo, int hi, t_op *op)
{
	int	target;
	int	seen;

	target = hi - lo;
	seen = 0;
	while (seen < target && *a)
	{
		if ((*a)->index >= lo && (*a)->index < hi)
		{
			pb(a, b, 1, op);
			seen++;
			if (*b && (*b)->next && (*b)->index < lo + (hi - lo) / 2)
				rb(b, 1, op);
		}
		else
			ra(a, 1, op);
	}
}

/* Pour b back onto a, largest rank first, rotating the short way. */
static void	push_back(t_node **a, t_node **b, t_op *op)
{
	t_node	*max;
	int		pos;
	int		size;

	while (*b)
	{
		max = find_max_idx(*b);
		pos = node_pos(*b, max);
		size = ft_lstsize(*b);
		if (pos <= size / 2)
		{
			while (*b != max)
				rb(b, 1, op);
		}
		else
		{
			while (*b != max)
				rrb(b, 1, op);
		}
		pa(a, b, 1, op);
	}
}

void	sort_medium(t_node **a, t_node **b, t_op *op)
{
	int	n;
	int	size;
	int	lo;

	n = ft_lstsize(*a);
	if (n <= 5)
	{
		sort_small(a, b, op);
		return ;
	}
	size = chunk_size_for(n);
	lo = 0;
	while (lo < n)
	{
		send_chunk(a, b, lo, lo + size, op);
		lo += size;
	}
	push_back(a, b, op);
}
