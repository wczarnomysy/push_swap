/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:58:33 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 20:03:51 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **a, t_node **b, int size, int *flag)
{
	if ((size >= 3 && size <= 5) || *flag == 1)
		sort_simple(a, b);
	if (*flag == 2)
		sort_medium(a, b);
	if (*flag == 3)
		radix_sort(a, b);
	if (*flag ==  4 || *flag == 0)
		adaptive_sort(a, b, disorder_check(*a));
}
