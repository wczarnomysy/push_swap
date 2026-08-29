/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:26:33 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 21:24:55 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static t_node	*find_max(t_node *b)
{
	t_node	*max;

	if (!b)
		return (NULL);
	max = b;
	while (b)
	{
		if (b->index > max->index)
			max = b;
		b = b->next;
	}
	return (max);
}

static void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed + chunk_size)
		{
			pb(a, b, 1);
			if ((*b)->index <= pushed + (chunk_size / 2))
				rb(b, 1);
			pushed++;
		}
		else
			ra(a, 1);
	}
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	t_node	*max;
	int		pos;
	int		size;

	while (*b)
	{
		max = find_max(*b);
		pos = node_pos(*b, max);
		size = ft_lstsize(*b);
		if (pos <= size / 2)
		{
			while (*b != max)
				rb(b, 1);
		}
		else
		{
			while (*b != max)
				rrb(b, 1);
		}
		pa(a, b, 1);
	}
}

int	node_pos(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target->index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	sort_medium(t_node **a, t_node **b)
{
	int	chunk_size;

	if (ft_lstsize(*a) <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}
/*
static int	chunk_size_for(int n)
{
	int	size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static void	group_by_chunks(t_node **a, t_node **b, int n, int chunk_size)
{
	int	low;
	int	high;
	int	remaining;

	low = 1;
	while (low <= n)
	{
		high = low + chunk_size - 1;
		if (high > n)
			high = n;
		remaining = ft_lstsize(*a);
		while (remaining-- > 0)
		{
			if ((*a)->index >= low && (*a)->index <= high)
				pb(a, b, 1);
			else
				ra(a, 1);
		}
		low += chunk_size;
	}
}

static void	sort_batch(t_node **a, t_node **b, int batch)
{
	int		len;
	t_node	*min;
	int		pos;
	int		i;

	i = 0;
	while (i++ < batch)
		pa(a, b, 1);
	len = batch;
	while (len > 0)
	{
		min = find_min(*a);
		pos = node_pos(*a, min);
		move_to_top(a, pos, len);
		pb(a, b, 1);
		len--;
	}
	i = 0;
	while (i++ < batch)
		rb(b, 1);
}

void	sort_medium(t_node **a, t_node **b)
{
	int	n;
	int	chunk_size;
	int	groups;
	int	first_batch;
	int	i;

	n = ft_lstsize(*a);
	if (n <= 1)
		return ;
	chunk_size = chunk_size_for(n);
	group_by_chunks(a, b, n, chunk_size);
	groups = (n + chunk_size - 1) / chunk_size;
	first_batch = n - chunk_size * (groups - 1);
	i = 0;
	while (i < groups)
	{
		if (i == 0)
			sort_batch(a, b, first_batch);
		else
			sort_batch(a, b, chunk_size);
		i++;
	}
	while (*b)
		pa(a, b, 1);
}*/
