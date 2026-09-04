/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by telmo             #+#    #+#             */
/*   Updated: 2026/09/04 20:02:03 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op(t_op *op)
{
	int	i;

	op->flag = FLAG_UNKNOWN;
	op->complexity = COMPLEXITY_UNKNOWN;
	op->bench = 0;
	op->disorder = 0.0f;
	op->total = 0;
	op->print = 1;
	i = 0;
	while (i < OP_COUNT)
		op->count[i++] = 0;
}
