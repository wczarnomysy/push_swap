/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by wczarnom          #+#    #+#             */
/*   Updated: 2026/09/04 18:56:43 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_int(const char *s, int *out)
{
	long	res;
	long	sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		res = res * 10 + (s[i++] - '0');
	}
	res = res * sign;
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return (*out = (int)res, 1);
}

int	has_duplicate(t_node *list, int value)
{
	while (list)
	{
		if (list->value == value)
			return (1);
		list = list->next;
	}
	return (0);
}
