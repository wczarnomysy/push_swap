/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:53:27 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/26 19:33:40 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node **list)
{
	int		index;
	t_node	*current;
	t_node	*tmp;

	tmp = *list;
	while (tmp)
	{
		index = 1;
		current = *list;
		while (current)
		{
			if (tmp->value > current->value)
			{
				index++;
			}
			current = current->next;
		}
		tmp->index = index;
		//printf("El index del valor %d es -> %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	return ;
}
