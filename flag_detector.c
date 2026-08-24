/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:43:52 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/14 17:14:02 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_detector(char *s, int flag)
{
	if (strncmp(s, "--simple", 20) == 0 && (flag == 1 || flag == 0))
		return (1);
	else if (strncmp(s, "--medium", 20) == 0 && (flag == 2 || flag == 0))
		return (2);
	else if (strncmp(s, "--complex", 20) == 0 && (flag == 3 || flag == 0))
		return (3);
	else if (strncmp(s, "--adaptive", 20) == 0 && (flag == 4 || flag == 0))
		return (4);
	return (0);
}
