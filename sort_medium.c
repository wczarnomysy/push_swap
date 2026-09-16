/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:26:33 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/16 21:20:07 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	send_chunk(t_node **a, t_node **b, t_range chunk_rank, t_op *op)
{
	int	target;
	int	seen;

	target = chunk_rank.hi - chunk_rank.lo;
	seen = 0;
	while (seen < target && *a)
	{
		if ((*a)->index >= chunk_rank.lo && (*a)->index < chunk_rank.hi)
		{
			pb(a, b, op);
			seen++;
			if (*b && (*b)->next && (*b)->index < chunk_rank.lo + (chunk_rank.hi
					- chunk_rank.lo) / 2)
				rb(b, op);
		}
		else
			ra(a, op);
	}
}

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
				rb(b, op);
		}
		else
		{
			while (*b != max)
				rrb(b, op);
		}
		pa(a, b, op);
	}
}

void	sort_medium(t_node **a, t_node **b, t_op *op)
{
	int		n;
	int		size;
	t_range	chunk_rank;

	n = ft_lstsize(*a);
	if (n <= 5)
	{
		sort_small(a, b, op);
		return ;
	}
	size = chunk_size_for(n);
	chunk_rank.lo = 0;
	while (chunk_rank.lo < n)
	{
		chunk_rank.hi = chunk_rank.lo + size;
		send_chunk(a, b, chunk_rank, op);
		chunk_rank.lo += size;
	}
	push_back(a, b, op);
}
