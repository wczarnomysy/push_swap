/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:58:10 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/01 14:45:55 by telmo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	radix_sort(t_node **a, t_node **b, t_op *op)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = get_stack_size(*a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(a, b, 1, op);
			else
				ra(a, 1, op);
			j++;
		}
		while (*b)
			pa(a, b, 1, op);
		i++;
	}
}
