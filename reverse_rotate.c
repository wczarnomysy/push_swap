/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:33:05 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 19:26:27 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a, int print)
{
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->prev->next = NULL;
	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void rrb(t_node **b, int print)
{
	t_node	*prev;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
