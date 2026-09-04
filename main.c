/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:59:28 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/04 20:01:42 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_arg(char *arg, t_node **a, t_op *op)
{
	t_node	*node;
	int		value;

	if (flag_detector(arg, op) != 0)
		return (1);
	if (!parse_int(arg, &value) || has_duplicate(*a, value))
		return (0);
	node = ft_lstnew(value);
	if (!node)
		return (0);
	ft_lstadd_back(a, node);
	return (1);
}

static int	process_arg(char *arg, t_node **a, t_op *op)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	if (!split[0])
		return (free_split(split), 0);
	j = 0;
	while (split[j])
	{
		if (!add_arg(split[j], a, op))
			return (free_split(split), 0);
		j++;
	}
	free_split(split);
	return (1);
}

static int	create_stack(int argc, char **argv, t_node **a, t_op *op)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_arg(argv[i], a, op))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_op	op;

	a = NULL;
	b = NULL;
	init_op(&op);
	if (!create_stack(argc, argv, &a, &op))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (!a)
		return (0);
	assign_index(&a);
	op.disorder = disorder_check(a);
	sort_stack(&a, &b, get_stack_size(a), &op);
	if (op.bench == 1)
		print_bench_results(&op);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
