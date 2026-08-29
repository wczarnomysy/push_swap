/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:59:28 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 21:23:48 by wczarnom         ###   ########.fr       */
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

void	create_stack(int argc, char *argv[], t_node **list, int *flag, int *bench)
{
	int		i;
	char	**arguments;
	int		j;

	i = 1;
	j = 0;
	arguments = NULL;
	while (i < argc)
	{
		arguments = ft_split(argv[i], ' ');
		j = 0;
		while (arguments[j])
		{
			if (flag_detector(arguments[j], flag) != 0)
				j++;
			else if (is_bench(arguments[j], bench) != 0)
				j++;
			else
			{
				create_node(arguments[j], list);
				j++;
			}
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     flag;
    int     bench;

    flag = 0;
    bench = 0;
    stack_a = NULL;
    stack_b = NULL;
    create_stack(argc, argv, &stack_a, &flag, &bench);
    assign_index(&stack_a);
    disorder_check(stack_a);
    
    // CORRECCIÓN: Pasar stack_a (por valor), NO &stack_a
    sort_stack(&stack_a, &stack_b, get_stack_size(stack_a), &flag);

    // Guardamos la cabecera original en una variable temporal para imprimir
    t_node *curr = stack_a;
    while (curr)
    {
        printf("valor a %d\n", curr->value);
        curr = curr->next;
    }
    return (0);
}
