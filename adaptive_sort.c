/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 19:58:38 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 20:04:16 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b, float disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, b);
	else if (disorder >= 0.5)
		radix_sort(a, b);
}