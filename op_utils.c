/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by telmo             #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op(t_op *op)
{
	int	i;

	op->flag = FLAG_ADAPTIVE;
	op->complexity = COMPLEXITY_UNKNOWN;
	op->bench = 0;
	op->disorder = 0.0f;
	op->total = 0;
	i = 0;
	while (i < OP_COUNT)
		op->count[i++] = 0;
}

void	do_op(t_op *op, t_opid id, int print)
{
	static const char	*const names[OP_COUNT] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n",
		"rr\n", "rra\n", "rrb\n", "rrr\n"};

	if (op)
	{
		op->count[id] += 1;
		op->total += 1;
	}
	if (print)
		write(1, names[id], ft_strlen(names[id]));
}
