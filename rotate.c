/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:03:07 by wczarnom          #+#    #+#             */
/*   Updated: 2026/08/26 16:03:57 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a, int print)
{
	t_node	*first;
	t_node	*tail;

	if (!*a || (*a)->next == NULL)
		return ;
	first = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	first->next = NULL;
	tail = *a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = first;
	first->prev = tail;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int print)
{
	t_node	*first;
	t_node	*tail;

	if (!*b || (*b)->next == NULL)
		return ;
	first = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	first->next = NULL;
	tail = *b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = first;
	first->prev = tail;
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	rra(t_node **a, int print)
{
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->next = *b;
	(*b)->prev = last;
	last->prev = NULL;
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
