/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:59:28 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/14 18:44:26 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(char *arguments, t_node **list)
{
	long	value;

	value = 0;
	is_valid(arguments);
	value = ft_atol(arguments);
	has_duplicate(*list, value);
	ft_lstadd_back(list, ft_lstnew(value));
}

void	create_stack(int argc, char *argv[], t_node **list)
{
	int		i;
	char	**arguments;
	int		j;
	int		flag_type;
	int		bench;

	i = 1;
	j = 0;
	flag_type = 0;
	bench = 0;
	arguments = NULL;
	while (i < argc)
	{
		arguments = ft_split(argv[i], ' ');
		j = 0;
		while (arguments[j])
		{
			if (flag_detector(arguments[j], flag_type) != 0)
			{
				flag_type = flag_detector(arguments[j], flag_type);
				j++;
			}
			else if (is_bench(arguments[j]) != 0)
			{
				bench = is_bench(arguments[j]);
				j++;
			}
			else
			{
				create_node(arguments[j], list);
				j++;
			}
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	create_stack(argc, argv, &stack_a);
	assign_index(&stack_a);
	disorder_check(stack_a);
	return (0);
}
