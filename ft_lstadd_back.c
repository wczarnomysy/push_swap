/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:50:42 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/14 17:15:11 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_node **list, t_node *new)
{
	t_node	*last;

	if (!new || !list)
		return ;
	if (!*list)
	{
		*list = new;
		new->prev = NULL;
		return ;
	}
	last = ft_lstlast(*list);
	last->next = new;
	new->prev = last;
}
