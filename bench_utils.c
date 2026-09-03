/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by telmo             #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((int)(nb / 10), fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	bench_put_count(const char *label, int n)
{
	write(2, label, ft_strlen(label));
	ft_putnbr_fd(n, 2);
}

void	bench_put_disorder(float d)
{
	int	scaled;

	scaled = (int)(d * 10000.0f + 0.5f);
	write(2, "[bench] disorder: ", 18);
	ft_putnbr_fd(scaled / 100, 2);
	write(2, ".", 1);
	if (scaled % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(scaled % 100, 2);
	write(2, "%\n", 2);
}

const char	*bench_strat_name(int flag)
{
	if (flag == FLAG_SIMPLE)
		return ("Simple");
	if (flag == FLAG_MEDIUM)
		return ("Medium");
	if (flag == FLAG_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

const char	*bench_class_name(int complexity)
{
	if (complexity == COMPLEXITY_SMALL)
		return ("O(n)");
	if (complexity == COMPLEXITY_SIMPLE)
		return ("O(n^2)");
	if (complexity == COMPLEXITY_MEDIUM)
		return ("O(n sqrt n)");
	if (complexity == COMPLEXITY_COMPLEX)
		return ("O(n log n)");
	return ("O(1)");
}
