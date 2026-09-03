/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:25:45 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	get_max_bits(int size)
{
	int	max_bits;
	int	max_num;

	if (size <= 1)
		return (0);
	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

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

void	move_to_top(t_node **a, int pos, int len, t_op *op)
{
	int	rra_steps;

	rra_steps = len - pos;
	if (pos <= rra_steps)
	{
		while (pos-- > 0)
			ra(a, 1, op);
	}
	else
	{
		while (rra_steps-- > 0)
			rra(a, 1, op);
	}
}
