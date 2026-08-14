/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:56:16 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/14 18:41:26 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(2, "ERROR\n", 6);
		exit (EXIT_FAILURE);
	}
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
	{
		write(2, "ERROR\n", 6);
		exit (EXIT_FAILURE);
	}
	while (s[i] <= '9' && s[i] >= '0')
		i++;
	if ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
	{
		write(2, "ERROR\n", 6);
		exit (EXIT_FAILURE);
	}
	return (1);
}

int	has_duplicate(t_node *list, int value)
{
	while (list)
	{
		if (list->value == value)
		{
			write(2, "ERROR\n", 6);
			exit (EXIT_FAILURE);
		}
		list = list->next;
	}
	return (1);
}
