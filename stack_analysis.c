/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:53:27 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node **list)
{
	int		index;
	int		pos;
	t_node	*current;
	t_node	*tmp;

	tmp = *list;
	pos = 1;
	while (tmp)
	{
		index = 0;
		current = *list;
		while (current)
		{
			if (tmp->value > current->value)
				index++;
			current = current->next;
		}
		tmp->pos = pos++;
		tmp->index = index;
		tmp = tmp->next;
	}
}

float	disorder_check(t_node *list)
{
	int		mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = list;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

int	ft_is_sorted(t_node *lst)
{
	if (!lst || !lst->next)
		return (1);
	while (lst->next != NULL)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}
