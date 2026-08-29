/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:55:15 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 19:22:37 by tguezala         ###   ########.fr       */
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

void	move_to_top(t_node **a, int pos, int len)
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
