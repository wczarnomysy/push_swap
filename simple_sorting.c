/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:06:20 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/29 21:25:40 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

static void	push_min_to_b(t_node **a, t_node **b, int len)
{
	t_node	*min;
	int		pos;

	min = find_min(*a);
	pos = node_pos(*a, min);
	move_to_top(a, pos, len);
	pb(a, b, 1);
}

static void	sort_four(t_node **a, t_node **b)
{
	push_min_to_b(a, b, 4);
	sort_three(a);
	pa(a, b, 1);
}

static void	sort_five(t_node **a, t_node **b)
{
	push_min_to_b(a, b, 5);
	push_min_to_b(a, b, 4);
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

void	sort_simple(t_node **a, t_node **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (len <= 1)
		return ;
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, 1);
		return ;
	}
	if (len == 3)
	{
		sort_three(a);
		return ;
	}
	if (len == 4)
	{
		sort_four(a, b);
		return ;
	}
	if (len == 5)
	{
		sort_five(a, b);
		return ;
	}
	/*while (len > 0)
	{
		push_min_to_b(a, b, len);
		len--;
	}
	while (*b)
		pa(a, b, 1);*/
	radix_sort(a, b);
}
