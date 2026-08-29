/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_detector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wczarnom <wczarnom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:43:52 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/29 21:22:23 by wczarnom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_detector(char *s, int *flag)
{
	if (ft_strncmp(s, "--simple", 20) == 0 && (*flag == 1 || *flag == 0))
	{
		*flag = 1;
		return (1);
	}
	else if (ft_strncmp(s, "--medium", 20) == 0 && (*flag == 2 || *flag == 0))
	{
		*flag = 2;
		return (2);
	}
	else if (ft_strncmp(s, "--complex", 20) == 0 && (*flag == 3 || *flag == 0))
	{
		*flag = 3;
		return (3);
	}
	else if (ft_strncmp(s, "--adaptive", 20) == 0 && (*flag == 4 || *flag == 0))
	{
		*flag = 4;
		return (4);
	}
	return (0);
}
