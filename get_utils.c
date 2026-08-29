/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:25:45 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 19:18:40 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_bits;
	int max_num;

	if (size <= 1)
		return (0);
	max_bits = 0;
	max_num =  size-1;
	while ((max_num >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

int	get_min_index(t_node **a)
{
	int		min;
	t_node	*tmp;

	if (!a)
		return (-1);
	tmp = *a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	get_pos_of_index(t_node **a, int target_index)
{
	int		pos;
	t_node	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == target_index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_stack_size(t_node *a)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = a;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
