/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:53:27 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 21:21:45 by wczarnom         ###   ########.fr       */
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
		tmp->pos = pos;
		pos++;
		tmp->index = index;
		tmp = tmp->next;
	}
	return ;
}
