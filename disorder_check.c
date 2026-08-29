/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:54:44 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 21:21:57 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_check(t_node *list)
{
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (list && list->next)
	{
		if (list->value > list->next->value)
			mistakes++;
		list = list->next;
		total_pairs++;
	}
	if (list != NULL && list->prev != NULL && list->next == NULL
		&& list->prev->value > list->value)
		mistakes++;
	total_pairs++;
	printf("Total pairs -> %d\nMistakes -> %d\n", total_pairs, mistakes);
	return (((float)mistakes / (float)total_pairs));
}
