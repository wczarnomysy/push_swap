/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:43:52 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/04 20:02:28 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_detector(char *s, t_op *op)
{
	if (ft_strncmp(s, "--bench", 8) == 0)
	{
		op->bench = 1;
		return (1);
	}
	if (ft_strncmp(s, "--simple", 9) == 0
		&& (op->flag == 1 || op->flag == 0))
		op->flag = FLAG_SIMPLE;
	else if (ft_strncmp(s, "--medium", 9) == 0
		&& (op->flag == 2 || op->flag == 0))
		op->flag = FLAG_MEDIUM;
	else if (ft_strncmp(s, "--complex", 10) == 0
		&& (op->flag == 3 || op->flag == 0))
		op->flag = FLAG_COMPLEX;
	else if (ft_strncmp(s, "--adaptive", 11) == 0
		&& (op->flag == 4 || op->flag == 0))
		op->flag = FLAG_ADAPTIVE;
	else
		return (0);
	return (1);
}
