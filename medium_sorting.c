/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/* ************************************************************************** */

#include "push_swap.h"

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
}
