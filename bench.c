/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by telmo             #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_strategy(t_op *op)
{
	const char	*name;
	const char	*cls;

	name = bench_strat_name(op->flag);
	cls = bench_class_name(op->complexity);
	write(2, "[bench] strategy: ", 18);
	write(2, name, ft_strlen(name));
	write(2, " / ", 3);
	write(2, cls, ft_strlen(cls));
	write(2, "\n", 1);
}

static void	put_swaps(t_op *op)
{
	bench_put_count("[bench] sa: ", op->count[OP_SA]);
	bench_put_count(" sb: ", op->count[OP_SB]);
	bench_put_count(" ss: ", op->count[OP_SS]);
	bench_put_count(" pa: ", op->count[OP_PA]);
	bench_put_count(" pb: ", op->count[OP_PB]);
	write(2, "\n", 1);
}

static void	put_rotates(t_op *op)
{
	bench_put_count("[bench] ra: ", op->count[OP_RA]);
	bench_put_count(" rb: ", op->count[OP_RB]);
	bench_put_count(" rr: ", op->count[OP_RR]);
	bench_put_count(" rra: ", op->count[OP_RRA]);
	bench_put_count(" rrb: ", op->count[OP_RRB]);
	bench_put_count(" rrr: ", op->count[OP_RRR]);
	write(2, "\n", 1);
}

void	print_bench_results(t_op *op)
{
	if (!op)
		return ;
	bench_put_disorder(op->disorder);
	put_strategy(op);
	bench_put_count("[bench] total_ops: ", op->total);
	write(2, "\n", 1);
	put_swaps(op);
	put_rotates(op);
}
