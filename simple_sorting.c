/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:06:20 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/26 19:25:33 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *a)
{
	t_node	*min;

	min = a;
	while (a)
	{
		if (a->index < min->index)
			min = a;
		a = a->next;
	}
	return (min);
}

static int	node_pos(t_node *a, t_node *target)
{
	int	pos;

	pos = 0;
	while (a != target)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

static void	move_to_top(t_node **a, int pos, int len)
{
	int	rra_steps;

	rra_steps = len - pos;
	if (pos <= rra_steps)
	{
		while (pos-- > 0)
			ra(a, 1);
	}
	else
	{
		while (rra_steps-- > 0)
			rra(a, 1);
	}
}

void	sort_simple(t_node **a, t_node **b)
{
	int		len;
	t_node	*min;
	int		pos;

	len = ft_lstsize(*a);
	if (len <= 1)
		return ;
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
		return ;
	}
	while (len > 0)
	{
		min = find_min(*a);
		pos = node_pos(*a, min);
		move_to_top(a, pos, len);
		pb(a, b, 1);
		len--;
	}
	while (*b)
		pa(a, b, 1);
}
